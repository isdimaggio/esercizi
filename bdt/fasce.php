<?php
require_once 'fun.php';
require_once 'navbar.php';

$breadcrumb = [
    [
        "link" => "",
        'text' => 'Gest. Fasce Orarie',
        'icon' => 'clock-history',
        "active" => true
    ]
];

$idSocio = $_SESSION['idSocio'];
check_session();

if (isset($_POST['giornoSettimana']) && isset($_POST['oraInizio']) && isset($_POST['oraFine'])) {
    
    $giornoSettimana = $con->real_escape_string($_POST['giornoSettimana']);
    $oraInizio = $con->real_escape_string($_POST['oraInizio']);
    $oraFine = $con->real_escape_string($_POST['oraFine']);

    // controlla che la fascia oraria da inserire non si sovrapponga 
    // con una fascia oraria dello stesso giorno gia esistente

    $fasce = $con->query(
        "SELECT * FROM fasceOrarie 
        WHERE idSocio = $idSocio 
        AND giornoSettimana = $giornoSettimana
        AND (
            (oraInizio <= '$oraInizio' AND oraFine >= '$oraInizio') OR
            (oraInizio <= '$oraFine' AND oraFine >= '$oraFine')
        )"
    );

    if ($fasce->num_rows > 0) {
        ?>
            <script>
                alert('La fascia oraria che stai cercando di inserire si sovrappone con una fascia oraria già esistente');
                window.location.href = 'fasce.php';
            </script>
        <?php
        die();
    }
    
    $con->query(
        "INSERT INTO fasceOrarie 
            (idSocio, giornoSettimana, oraInizio, oraFine) 
        VALUES ($idSocio, '$giornoSettimana', '$oraInizio', '$oraFine')");

    header("Location: fasce.php");
    exit();
}

if (isset($_GET['idRimozione'])) {
    $idRimozione = $con->real_escape_string($_GET['idRimozione']);
    $con->query("DELETE FROM fasceOrarie WHERE idFasciaOraria = $idRimozione");
    header("Location: fasce.php");
    exit();
}

page_start('TIpi Prestazioni Accettate');
T_navbar($breadcrumb);

?>

<main>
    <form action="" method="post">
        <div class="row g-2 mb-2">
            <div class="col">
                <div class="form-floating">
                    <select class="form-select" id="giornoSettimana" name="giornoSettimana" >
                        <option selected disabled>Seleziona...</option>
                        <option value="0">Lunedì</option>
                        <option value="1">Martedì</option>
                        <option value="2">Mercoledì</option>
                        <option value="3">Giovedì</option>
                        <option value="4">Venerdì</option>
                        <option value="5">Sabato</option>
                        <option value="6">Domenica</option>
                    </select>
                    <label for="giornoSettimana">Giorno della settimana</label>
                </div>
            </div>
            <div class="col">
                <div class="form-floating">
                    <input type="time" class="form-control" id="oraInizio" name="oraInizio">
                    <label for="oraInizio">Ora inizio</label>
                </div>
            </div>
            <div class="col">
                <div class="form-floating">
                    <input type="time" class="form-control" id="oraFine" name="oraFine">
                    <label for="oraFine">Ora fine</label>
                </div>
            </div>
            <div class="col col-auto">
                <button type="submit" class="btn btn-outline-secondary h-100">
                    <i class="bi bi-plus"></i>
                    Aggiungi
                </button>
            </div>
        </div>
    </form>
    <hr>
    <table class="table table-striped table-bordered table-hover mt-2">
        <thead class="table-light">
            <tr>
                <th scope="col">Giorno</th>
                <th scope="col">Ora inizio</th>
                <th scope="col">Ora fine</th>
                <th scope="col">Azioni</th>
            </tr>
        </thead>
        <tbody>
            <?php
                $res = $con->query(
                    "SELECT 
                        giornoSettimana, oraInizio, oraFine, idFasciaOraria
                    FROM 
                        fasceOrarie
                    WHERE 
                        idSocio = $idSocio
                    ORDER BY 
                        giornoSettimana ASC, oraInizio ASC"
                );
                while($row = $res->fetch_assoc()){ ?>
                    <tr>
                        <td><?= convertiGiornoSettimana($row['giornoSettimana']) ?></td>
                        <td><?= accorciaTime($row['oraInizio']) ?></td>
                        <td><?= accorciaTime($row['oraFine']) ?></td>
                        <td>
                            <a href='fasce.php?idRimozione=<?=$row['idFasciaOraria']?>' class='btn btn-outline-secondary'>
                                <i class='bi bi-trash'></i>
                                Rimuovi
                            </a>
                        </td>
                    </tr>
            <?php } ?>
        </tbody>
    </table>
</main>

<?php
page_end();