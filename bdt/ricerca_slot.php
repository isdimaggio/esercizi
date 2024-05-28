<?php
require_once 'fun.php';
require_once 'navbar.php';

$breadcrumb = [
    [
        "link" => "",
        "text" => "Prenota Prestazione",
        "icon" => "calendar2-check",
        "active" => true
    ]
];

check_session();
$idRichiedente = $_SESSION['idSocio'];
$credito = calc_balance($idRichiedente);

if ($_SERVER['REQUEST_METHOD'] == "POST") {

    if(isset($_POST['action']) && $_POST['action'] == "prenota"){
        $idRichiedente = $con->real_escape_string($_POST['idRichiedente']);
        $idPrestante = $con->real_escape_string($_POST['idPrestante']);
        $data = $con->real_escape_string($_POST['data']);
        $ora = $con->real_escape_string($_POST['ora']);
        $durata = $con->real_escape_string($_POST['durata']);
        $idTipoPrestazione = $con->real_escape_string($_POST['idTipoPrestazione']);

        $con->query(
            "INSERT INTO prestazioni 
            (idTipoPrestazione, idSocioPrestante, idSocioRicevente, dataOra, durata, stato)
            VALUES ($idTipoPrestazione, $idRichiedente, $idPrestante, '$data $ora', $durata, 'inviata')
        ");

        header("Location: /?success=1");
        exit();
    }

    // dati utili alle query
    $idZona = $con->query("SELECT idZona FROM soci WHERE idSocio = $idRichiedente")->fetch_assoc()['idZona'];
    $nomeZona = $con->query("SELECT denominazione FROM zone WHERE idZona = $idZona")->fetch_assoc()['denominazione'];
    $idTipoPrestazione = $con->real_escape_string($_POST['idTipoPrestazione']);
    $nomePrestazione = $con->query("SELECT denominazione FROM tipiPrestazione WHERE idTipoPrestazione = $idTipoPrestazione")->fetch_assoc()['denominazione'];
    $data = $con->real_escape_string($_POST['data']);

    $giornoSettimana = date('w', strtotime($data)) - 1;
    if ($giornoSettimana == -1) $giornoSettimana = 6; // php merda 

    $oraInizio = $con->real_escape_string($_POST['ora']) . ":00"; 
    $durata = $con->real_escape_string($_POST['durata']);
    $oraFine = date('H:i', strtotime($oraInizio) + $durata * 3600) . ":00";
    $dataLimite = $data . " " . $oraFine;

    $error = "";

    // controlla se la data selezionata è nel passato (non dovrebbe essere possibile ma meglio controllare)
    if (strtotime($dataLimite) < strtotime(date('Y-m-d'))) {
        $error = "Non puoi prenotare prestazioni nel passato";
    }

    if ($durata > $credito) {
        $error = "Non hai abbastanza credito per prenotare una prestazione di $durata ore";
    }

    // prestazioni esistenti
    $prestazioniOverlap = $con->query(
        "SELECT * FROM prestazioniOrariDef
        WHERE idSocioPrestante = $idRichiedente 
        AND dataPrestazione = '$data' 
        AND oraFine > '$oraInizio' 
        AND oraInizio < '$oraFine'
    ");

    if ($prestazioniOverlap->num_rows > 0) {
        $error = "Hai già una prestazione da dare in quella fascia oraria che si sovrappone con la tua richiesta";
    }

    page_start("Prenota prestazione");
    T_navbar($breadcrumb);

    if ($error != "") {
        $link_go_back = "<a class='alert-link' href='javascript:history.back()'>Riprova</a>";
        echo "<main><div class='alert alert-danger' role='alert'>$error. $link_go_back</div><main>";
        page_end();
        die();
    }

    // SELEZIONARE SOCI CHE:
    // 1. sono approvati in società
    // 2. non sono il richiedente
    // 3. sono abilitati a fare quel tipo di prestazione
    // 4. hanno la stessa zona
    // 5. hanno dato la disponibilità  per quel giorno della settimana in quella fascia oraria
    // 6. non hanno già una prestazione che si sovrapponga

    $querySoci = 
    "SELECT
        idSocio,
        nome,
        cognome,
        email,
        numTelefono,
        indirizzo
    FROM soci
    WHERE 
        sbloccato = 1 AND
        idSocio != $idRichiedente AND
        $idTipoPrestazione IN (
            SELECT idTipoPrestazione 
            FROM sociTipiPrestazione 
            WHERE idSocio = soci.idSocio
        ) AND soci.idZona = $idZona AND
        idSocio IN (
            SELECT idSocio 
            FROM fasceOrarie 
            WHERE 
                giornoSettimana = $giornoSettimana AND 
                oraInizio <= '$oraInizio' AND 
                oraFine >= '$oraFine'
        ) AND
        idSocio NOT IN (
            SELECT idSocioPrestante
            FROM prestazioniOrariDef
            WHERE 
                dataPrestazione = '$data' AND
                oraFine > '$oraInizio' AND
                oraInizio < '$oraFine'
        )
    ";

    $listaSociDisponibili = $con->query($querySoci);
    ?>

    <main>
        <div class="alert alert-secondary" role="alert">
            La tua ricerca: in zona 
            <b><?= $nomeZona ?></b> 
            in data <b><?= prettyDate($data) ?></b> 
            alle ore <b><?= prettyTime($oraInizio) ?></b> 
            per la durata di <b><?= $durata ?> ore</b>
            chiedo la prestazione di tipo <b><?= $nomePrestazione ?></b>
        </div>
        <hr>
        <center class="table-banner">
            <b>SOCI DISPONIBILI</b>
        </center>
        <table class="table table-striped table-bordered">
            <thead class="table-light">
                <tr>
                    <th>Nome</th>
                    <th>Cognome</th>
                    <th>Email</th>
                    <th>Telefono</th>
                    <th>Indirizzo</th>
                    <th>Prenota</th>
                </tr>
            </thead>
            <tbody>
                <?php
                if ($listaSociDisponibili->num_rows == 0) {
                ?>
                    <tr>
                        <td colspan="6" class="text-center">
                            Nessun socio disponibile per la ricerca effettuata.
                            <a class="alert-link" href="javascript:history.back()">Riprova</a>
                        </td>
                    </tr>
                <?php } else {
                    while ($socio = $listaSociDisponibili->fetch_assoc()) { ?>
                        <tr>
                            <td><?= $socio['nome'] ?></td>
                            <td><?= $socio['cognome'] ?></td>
                            <td><?= $socio['email'] ?></td>
                            <td><?= $socio['numTelefono'] ?></td>
                            <td><?= $socio['indirizzo'] ?></td>
                            <td>
                                <button class="btn btn-outline-secondary" onclick="prenota(<?= $socio['idSocio'] ?>, '<?= $data ?>', '<?= $oraInizio ?>', <?= $durata ?>, <?= $idTipoPrestazione ?>)">
                                    <i class="bi bi-calendar-plus"></i>
                                    Prenota
                                </button>
                            </td>
                        </tr>
                    <?php }
                } ?>
            </tbody>
        </table>
    </main>

    <form action="" method="post">
        <input type="hidden" name="action" value="prenota">
        <input type="hidden" name="idRichiedente" value="<?= $idRichiedente ?>">
        <input type="hidden" name="idPrestante" id="idPrestante">
        <input type="hidden" name="data" id="data">
        <input type="hidden" name="ora" id="ora">
        <input type="hidden" name="durata" id="durata">
        <input type="hidden" name="idTipoPrestazione" id="idTipoPrestazione">
    </form>

    <script>
        function prenota(idSocio, data, ora, durata, idTipoPrestazione){
            document.getElementById('idPrestante').value = idSocio;
            document.getElementById('data').value = data;
            document.getElementById('ora').value = ora;
            document.getElementById('durata').value = durata;
            document.getElementById('idTipoPrestazione').value = idTipoPrestazione;
            document.querySelector('form').submit();
        }
    </script>

    <?php
    page_end();
    die();
}

page_start('Prenota prestazione');
T_navbar($breadcrumb);

if($credito < 1){
    echo "<main><div class='alert alert-danger' role='alert'>Non hai abbastanza credito per prenotare una prestazione</div><main>";
    page_end();
    die();
}

?>

<main>
    <form action="" method="post">
        <div class="row g-2 mb-2">
            <div class="col">
                <div class="form-floating">
                    <select class="form-select" id="idTipoPrestazione" name="idTipoPrestazione">
                        <option selected disabled>Seleziona...</option>
                        <?php
                            $res = $con->query("SELECT * FROM tipiPrestazione");
                            while($row = $res->fetch_assoc()){
                                echo "<option value='{$row['idTipoPrestazione']}'>{$row['denominazione']}</option>";
                            }
                        ?>
                    </select>
                    <label for="idTipoPrestazione">Tipo Prestazione</label>
                </div>
            </div>
            <div class="col">
                <div class="form-floating">
                    <input type="date" class="form-control" id="data" name="data" min="<?= date("Y-m-d") ?>" required>
                    <label for="data">Data</label>
                </div>
            </div>
            <div class="col">
                <div class="form-floating">
                    <input type="time" class="form-control" id="ora" name="ora" required>
                    <label for="ora">Ora</label>
                </div>
            </div>
            <div class="col">
                <div class="form-floating">
                    <input type="number" class="form-control" id="durata" name="durata" max='<?= $credito ?>' required>
                    <label for="durata">Durata (ore) [CREDITO: <?= $credito ?>] </label>
                </div>
            </div>
            <div class="col col-auto">
                <button type="submit" class="btn btn-outline-secondary h-100">
                    <i class="bi bi-search"></i>
                    Ricerca soci disponibili
                </button>
            </div>
        </div>
    </form>
    <hr>
    <?php 
    if ($_SERVER['REQUEST_METHOD'] == "POST"){ ?>

    <?php } ?>
</main>

<?php
page_end();