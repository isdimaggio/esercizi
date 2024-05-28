<?php
require_once 'fun.php';
require_once 'navbar.php';

check_session();
page_start('Home');
T_navbar("hp");

$idSocio = $_SESSION['idSocio'];
$interval = 8;

$queryPrestazioniInEntrata = 
"SELECT 
    prestazioni.idPrestazione,
    tipiPrestazione.denominazione AS tipoPrestazione,
    soci.idSocio,
    soci.nome AS nomeSocio,
    soci.cognome AS cognomeSocio,
    prestazioni.dataOra,
    prestazioni.durata,
    prestazioni.stato
FROM
    prestazioni,
    tipiPrestazione,
    soci
WHERE
    prestazioni.idSocioPrestante = $idSocio AND
    prestazioni.idTipoPrestazione = tipiPrestazione.idTipoPrestazione AND
    prestazioni.idSocioPrestante = soci.idSocio AND
    prestazioni.stato != 'annullataPrestante' AND
    (
        prestazioni.dataOra > NOW() OR
        (
            (
                prestazioni.stato = 'inviata' OR
                prestazioni.stato = 'accettata' OR
                prestazioni.stato = 'annullataRicevente'
            ) AND prestazioni.dataOra > NOW() - INTERVAL $interval DAY
        )
    )
ORDER BY prestazioni.dataOra DESC;
";

$queryPrestazioniInUscita = 
"SELECT 
    prestazioni.idPrestazione,
    tipiPrestazione.denominazione AS tipoPrestazione,
    soci.idSocio,
    soci.nome AS nomeSocio,
    soci.cognome AS cognomeSocio,
    prestazioni.dataOra,
    prestazioni.durata,
    prestazioni.stato
FROM
    prestazioni,
    tipiPrestazione,
    soci
WHERE
    prestazioni.idSocioRicevente = $idSocio AND
    prestazioni.idTipoPrestazione = tipiPrestazione.idTipoPrestazione AND
    prestazioni.idSocioPrestante = soci.idSocio AND
    prestazioni.stato != 'annullataRicevente' AND
    (
        prestazioni.dataOra > NOW() OR
        (
            (
                prestazioni.stato = 'inviata' OR
                prestazioni.stato = 'accettata' OR
                prestazioni.stato = 'annullataPrestante'
            ) AND prestazioni.dataOra > NOW() - INTERVAL $interval DAY
        )
    )
ORDER BY prestazioni.dataOra DESC;
";
?>

<main>

    <?php if(isset($_GET['success']) && $_GET['success'] == 1) { ?>
        <div class="alert alert-success" id="succ" role="alert">
            Prenotazione effettuata con successo
        </div>
    <?php } else if(isset($_GET['success']) && $_GET['success'] == 2) { ?>
        <div class="alert alert-success" id="succ" role="alert">
            Prestazione annullata con successo
        </div>
    <?php } ?>

    <div class="alert alert-secondary" role="alert">
        Il tuo credito è di: <b><?= calc_balance($idSocio) ?> ore</b>
    </div>

    <center class="table-banner">
        <b>PRESTAZIONI IN USCITA</b>
    </center>
    <table class="table table-striped table-bordered">
        <thead class="table-light">
            <tr>
                <th>Tipo Prestazione</th>
                <th>Socio</th>
                <th>Data e Ora</th>
                <th>Durata</th>
                <th>Stato</th>
                <th>Operazioni</th>
            </tr>
        </thead>
        <tbody>
            <?php
            $res = $con->query($queryPrestazioniInEntrata);
            if ($res->num_rows == 0) { ?>
                <tr>
                    <td colspan="6" class="text-center">Nessuna prestazione in uscita</td>
                </tr>
            <?php } else {
            while ($row = $res->fetch_assoc()) {
                ?>
                    <tr>
                        <td><?= $row['tipoPrestazione'] ?></td>
                        <td><?= linkSocio($row['idSocio'], $row['nomeSocio'], $row['cognomeSocio']) ?></td>
                        <td><?= prettyDateTime($row['dataOra']) ?></td>
                        <td><?= $row['durata'] ?> ore</td>
                        <td><?= enumToStato($row['stato']); ?></td>
                        <td>
                            <?php if ($row['stato'] == 'inviata') { ?>
                                <a href="accetta_prestazione.php?id=<?= $row['idPrestazione'] ?>" class="btn btn-outline-success">
                                    <i class="bi bi-check"></i>
                                    Accetta
                                </a>
                                <a href="annulla_prestazione.php?id=<?= $row['idPrestazione'] ?>" class="btn btn-outline-danger">
                                    <i class="bi bi-x"></i>
                                    Rifiuta
                                </a>
                            <?php } else if ($row['stato'] == 'accettata') { ?>
                                <?php if ((strtotime($row['dataOra']) + ($row["durata"] * 3600)) < time()) { ?>
                                    <a href="accetta_prestazione.php?id=<?= $row['idPrestazione'] ?>" class="btn btn-outline-success">
                                        <i class="bi bi-check"></i>
                                        Conferma Esecuzione
                                    </a>
                                <?php } else {
                                    //print ((strtotime($row['dataOra']) + ($row["durata"] * 3600)) . " vs ". time());
                                } ?>
                                <a href="annulla_prestazione.php?id=<?= $row['idPrestazione'] ?>" class="btn btn-outline-danger">
                                    <i class="bi bi-x"></i>
                                    Annulla
                                </a>
                            <?php } ?>
                        </td>
                    </tr>
                <?php }
            } ?>
        </tbody>
    </table>
    <center class="table-banner">
        <b>PRESTAZIONI IN ENTRATA</b>
    </center>
    <table class="table table-striped table-bordered">
        <thead class="table-light">
            <tr>
                <th>Tipo Prestazione</th>
                <th>Socio</th>
                <th>Data e Ora</th>
                <th>Durata</th>
                <th>Stato</th>
                <th>Operazioni</th>
            </tr>
        </thead>
        <tbody>
            <?php
            $res = $con->query($queryPrestazioniInUscita);
            if ($res->num_rows == 0) {
            ?>
                <tr>
                    <td colspan="6" class="text-center">Nessuna prestazione in entrata</td>
                </tr>
                <?php
            } else {
            while ($row = $res->fetch_assoc()) {
                ?>
                    <tr>
                        <td><?= $row['tipoPrestazione'] ?></td>
                        <td><?= linkSocio($row['idSocio'], $row['nomeSocio'], $row['cognomeSocio']) ?></td>
                        <td><?= prettyDateTime($row['dataOra']) ?></td>
                        <td><?= $row['durata'] ?> ore</td>
                        <td><?= enumToStato($row['stato'], true); ?></td>
                        <td>
                            <?php if ($row['stato'] == 'inviata' || $row['stato'] == 'accettata') { ?>
                                <a href="annulla_prestazione.php?id=<?= $row['idPrestazione'] ?>" class="btn btn-outline-danger">
                                    <i class="bi bi-x"></i>
                                    Annulla
                                </a>
                            <?php } ?>
                        </td>
                    </tr>
                <?php
                }
            }
            ?>
        </tbody>
    </table>

    <script>
        setTimeout(() => {
            document.getElementById('succ').style.display = 'none';
        }, 3000);
    </script>

</main>

<?php
page_end();
