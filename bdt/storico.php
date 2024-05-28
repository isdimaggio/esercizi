<?php
require_once 'fun.php';
require_once 'navbar.php';

check_session();
page_start('Home');
T_navbar("hp");

$idSocio = $_SESSION['idSocio'];

$queryPrestazioni = "SELECT 
    prestazioni.idPrestazione,
    tipiPrestazione.denominazione AS tipoPrestazione,
    sociPrestanti.idSocio AS idSocioPrestante,
    sociPrestanti.nome AS nomeSocioPrestante,
    sociPrestanti.cognome AS cognomeSocioPrestante,
    sociRiceventi.idSocio AS idSocioRicevente,
    sociRiceventi.nome AS nomeSocioRicevente,
    sociRiceventi.cognome AS cognomeSocioRicevente,
    prestazioni.dataOra,
    prestazioni.durata,
    prestazioni.stato
FROM
    prestazioni
JOIN soci AS sociPrestanti 
    ON prestazioni.idSocioPrestante = sociPrestanti.idSocio
JOIN soci AS sociRiceventi 
    ON prestazioni.idSocioRicevente = sociRiceventi.idSocio
JOIN tipiPrestazione 
    ON prestazioni.idTipoPrestazione = tipiPrestazione.idTipoPrestazione
WHERE
    prestazioni.idSocioPrestante = $idSocio OR
    prestazioni.idSocioRicevente = $idSocio 
ORDER BY prestazioni.dataOra DESC;
";
?>

<main>
    <table class="table table-striped table-bordered">
        <thead class="table-light">
            <tr>
                <th>Tipo Prestazione</th>
                <th>Socio Prestante</th>
                <th>Socio Ricevente</th>
                <th>Data e Ora</th>
                <th>Durata</th>
                <th>Stato</th>
            </tr>
        </thead>
        <tbody>
            <?php
            $res = $con->query($queryPrestazioni);
            if ($res->num_rows == 0) {
            ?>
                <tr>
                    <td colspan="6" class="text-center">Nessuna prestazione nello storico</td>
                </tr>
                <?php
            } else {
            while ($row = $res->fetch_assoc()) {
                ?>
                    <tr>
                        <td><?= $row['tipoPrestazione'] ?></td>
                        <td><?= linkSocio($row['idSocioPrestante'], $row['nomeSocioPrestante'], $row['cognomeSocioPrestante']) ?></td>
                        <td><?= linkSocio($row['idSocioRicevente'], $row['nomeSocioRicevente'], $row['cognomeSocioRicevente']) ?></td>
                        <td><?= prettyDateTime($row['dataOra']) ?></td>
                        <td><?= $row['durata'] ?> ore</td>
                        <td><?= enumToStato($row['stato']); ?></td>
                    </tr>
                <?php
                }
            }
            ?>
        </tbody>
    </table>
</main>

<?php
page_end();