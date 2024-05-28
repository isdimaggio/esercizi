<?php

require_once 'database.php';

// imposta fuso orario in Europe/Rome
date_default_timezone_set('Europe/Rome');

$con = new mysqli(
    $config['host'], 
    $config['username'], 
    $config['password'], 
    $config['dbname']
);

if ($con->connect_error) {
    die('Errore connessione al database: ' . $con->connect_error);
}

session_start();

function check_session($mustBeLoggedIn = true, $permessoSegreteria = false){
    if($mustBeLoggedIn && !isset($_SESSION['idSocio'])){
        header('Location: login.php');
        die();
    }

    if(!$mustBeLoggedIn && isset($_SESSION['idSocio'])){
        header('Location: ./');
        die();
    }

    if($permessoSegreteria && in_array('segreteria', $_SESSION['groups']) == false){
        header('Location: ./');
        die();
    }
}

function page_start($title){ ?>
<!DOCTYPE html>
<html lang="it">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?= $title ?> - Banca Del Tempo</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
    <link rel="stylesheet" href="assets/style.css">
    <link rel="apple-touch-icon" sizes="180x180" href="icons/apple-touch-icon.png">
    <link rel="icon" type="image/png" sizes="32x32" href="icons/favicon-32x32.png">
    <link rel="icon" type="image/png" sizes="16x16" href="icons/favicon-16x16.png">
    <link rel="manifest" href="icons/site.webmanifest">
    <link rel="mask-icon" href="icons/safari-pinned-tab.svg" color="#5bbad5">
    <link rel="shortcut icon" href="icons/favicon.ico">
    <meta name="msapplication-TileColor" content="#da532c">
    <meta name="msapplication-config" content="icons/browserconfig.xml">
    <meta name="theme-color" content="#ffffff">
    <?php
    global $NEEDS_LEAFLET;
    if(isset($NEEDS_LEAFLET) && $NEEDS_LEAFLET){ ?>
        <link rel="stylesheet" href="https://unpkg.com/leaflet/dist/leaflet.css" />
        <link rel="stylesheet" href="https://unpkg.com/@jonatanheyman/leaflet-areaselect/src/leaflet-areaselect.css" />
        <script src="https://unpkg.com/leaflet/dist/leaflet.js"></script>
        <script src="https://unpkg.com/@jonatanheyman/leaflet-areaselect/src/leaflet-areaselect.js"></script>
        <script src="https://unpkg.com/jquery"></script>
    <?php } ?>
</head>
<body>
<?php }

function page_end(){ ?>

<div class="modal fade" id="socioModal" tabindex="-1" aria-labelledby="modalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <h1 class="modal-title fs-5" id="modalLabel">Informazioni sul socio</h1>
        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
      </div>
      <div class="modal-body">
        <div id="bloccoInfo">
            <b>Nome:</b> <span id="nomeInfo"></span><br>
            <b>Cognome:</b> <span id="cognomeInfo"></span><br>
            <b>Email:</b> <span id="emailInfo"></span><br>
            <b>Numero di telefono:</b> <span id="numTelefonoInfo"></span><br>
            <b>Indirizzo:</b> <span id="indirizzoInfo"></span><br>
        </div>
        <div class="alert alert-danger" id="bloccoErrore" role="alert">
            Impossibile recuperare le informazioni sul socio.
        </div>
      </div>
    </div>
  </div>
</div>

<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
<script src="https://code.jquery.com/jquery-3.7.1.min.js"></script>

<script>
    var socioModal = new bootstrap.Modal($('#socioModal'))

    function infoSocio(idSocio) {
        $.ajax({
            url: 'info_socio_ajax.php?id=' + idSocio,
            success: function(data) {

                $('#bloccoInfo').show();
                $('#bloccoErrore').hide();

                data = JSON.parse(data);
                $('#nomeInfo').text(data.nome);
                $('#cognomeInfo').text(data.cognome);
                $('#emailInfo').text(data.email);
                $('#numTelefonoInfo').text(data.numTelefono);
                $('#indirizzoInfo').text(data.indirizzo);
            },
            error: function(){
                $('#bloccoInfo').hide();
                $('#bloccoErrore').show();
            }
        });
        socioModal.show()
    }
</script>
</body>
</html>
<?php }

function F_userinfo_displayname(){
    global $_SESSION;
    return $_SESSION['nome'] . ' ' . $_SESSION['cognome'];
}

function F_userinfo_mail(){
    global $_SESSION;
    return $_SESSION['email'];
}

function F_userinfo_gravatar(){
    $md5 = md5(
        strtolower(
            trim(F_userinfo_mail())));
    return "https://www.gravatar.com/avatar/$md5?s=32&d=mp";
}

function F_compare_permissions($groups){
    foreach ($groups as $group) {
        if (in_array($group, $_SESSION['groups'])) {
            return true;
        }
    }
    return false;
}

function calc_balance($idSocio){
    global $con;
    $idSocio = $con->real_escape_string($idSocio);
    $sql = 
    "SELECT (
        IFNULL(
            (SELECT 
                SUM(durata) 
            FROM prestazioni 
            WHERE 
                idSocioPrestante = $idSocio AND 
                stato = 'eseguita'
            ), 0
        ) - 
        IFNULL(
            (SELECT 
                SUM(durata) 
            FROM prestazioni 
            WHERE 
                idSocioRicevente = $idSocio AND 
                stato = 'eseguita'
            ), 0
        )
    ) AS balance;";
    $result = $con->query($sql);
    $row = $result->fetch_assoc();
    return $row['balance'];
}

function prettyDateTime($str){
    return date('d/m/Y H:i', strtotime($str));
}

function prettyDate($str){
    return date('d/m/Y', strtotime($str));
}

function prettyTime($str){
    return date('H:i', strtotime($str));
}

function convertiGiornoSettimana($giorno){
    switch ($giorno) {
        case 0:
            return 'Lunedì';
        case 1:
            return 'Martedì';
        case 2:
            return 'Mercoledì';
        case 3:
            return 'Giovedì';
        case 4:
            return 'Venerdì';
        case 5:
            return 'Sabato';
        case 6:
            return 'Domenica';
    }
}

function accorciaTime($str){
    return substr($str, 0, 5);
}

function enumToStato($str, $bool = false){
    switch ($str) {
        case 'inviata':
            return $bool ? 'Attendi conferma' : 'Attende conferma';
        case 'accettata':
            return 'Accettata';
        case 'eseguita':
            return 'Eseguita';
        case 'annullataPrestante':
            return 'Annullata dal socio prestante';
        case 'annullataRicevente':
            return 'Annullata dal socio ricevente';
    }
}

function randomPassword($len) {
    $chars = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';
    $charsLen = strlen($chars);
    $pass = '';
    for ($i = 0; $i < $len; $i++) {
        $pass .= $chars[rand(0, $charsLen - 1)];
    }
    return $pass;
}

function linkSocio($idSocio, $nome, $cognome){
    return "<a href='javascript:infoSocio($idSocio)'>$nome $cognome</a>";
}

$config_navbar = [
    [
        'name' => 'Home',
        'url' => './',
        'icon' => 'house-door',
        'roles' => ['standard']
    ],
    [
        'name' => 'Prenota',
        'url' => 'ricerca_slot.php',
        'icon' => 'calendar2-check',
        'roles' => ['standard']
    ],
    [
        'name' => 'Storico Prestazioni',
        'url' => 'storico.php',
        'icon' => 'database',
        'roles' => ['standard']
    ],
    [
        'name' => 'Gest. Fasce Orarie',
        'url' => 'fasce.php',
        'icon' => 'clock-history',
        'roles' => ['standard']
    ],
    [
        'name' => 'Tipi Prest. Accettate',
        'url' => 'acc_tipi_prest.php',
        'icon' => 'wrench',
        'roles' => ['standard']
    ],
    [
        'name' => 'Gestione',
        'icon' => 'gear',
        'roles' => ['segreteria'],
        'sub' => [
            [
                'name' => 'Gestione tipi prestazione',
                'url' => 'tipi_prestazione.php',
                'icon' => 'wrench-adjustable-circle',
                'roles' => ['segreteria']
            ],
            [
                'name' => 'Inserisci Zona',
                'url' => 'ins_zona.php',
                'icon' => 'geo-alt',
                'roles' => ['segreteria']
            ],
            [
                'name' => 'Lista Zone',
                'url' => 'zone.php',
                'icon' => 'map',
                'roles' => ['segreteria']
            ],
            [
                'name' => 'Gestione Soci',
                'url' => 'soci.php',
                'icon' => 'people',
                'roles' => ['segreteria']
            ]
        ]
    ]
];