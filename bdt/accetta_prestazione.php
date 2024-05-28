<?php
require_once 'fun.php';

check_session(true);

if(!isset($_GET['id'])){
    header('Location: /');
    die();
}
$id = $con->real_escape_string($_GET['id']);
$prestazione = $con->query("SELECT * FROM prestazioni WHERE idPrestazione = $id")->fetch_assoc();

if ($_SESSION['idSocio'] != $prestazione['idSocioPrestante'] && $_SESSION['idSocio'] != $prestazione['idSocioRicevente']){
    header('Location: /');
    die();
}else {
    if($prestazione['stato'] == 'inviata'){
        $con->query("UPDATE prestazioni SET stato = 'accettata' WHERE idPrestazione = $id");
    } else if ($prestazione['stato'] == 'accettata') {
        if ((strtotime($row['dataOra']) + ($row["durata"] * 3600)) < time()) {
            $con->query("UPDATE prestazioni SET stato = 'eseguita' WHERE idPrestazione = $id");
        }
    }
}
header('Location: /');