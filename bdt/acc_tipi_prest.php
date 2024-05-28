<?php
require_once 'fun.php';
require_once 'navbar.php';

$breadcrumb = [
    [
        "link" => "",
        "text" => "Tipi Prestazioni Accettate",
        "icon" => "wrench",
        "active" => true
    ]
];

$idSocio = $_SESSION['idSocio'];
check_session();

if (isset($_POST['idTipoPrestazione'])) {
    $idTipoPrestazione = $con->real_escape_string($_POST['idTipoPrestazione']);
    $con->query("INSERT INTO sociTipiPrestazione (idSocio, idTipoPrestazione) VALUES ($idSocio, $idTipoPrestazione)");
    header("Location: acc_tipi_prest.php");
    exit();
}

if (isset($_GET['idRimozione'])) {
    $idRimozione = $con->real_escape_string($_GET['idRimozione']);
    $con->query("DELETE FROM sociTipiPrestazione WHERE idSocioTipoPrestazione = $idRimozione");
    header("Location: acc_tipi_prest.php");
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
                    <select class="form-select" id="idTipoPrestazione" name="idTipoPrestazione">
                        <option selected disabled>Seleziona...</option>
                        <?php
                            $res = $con->query("SELECT * FROM tipiPrestazione");
                            while($row = $res->fetch_assoc()){
                                echo "<option value='{$row['idTipoPrestazione']}'>{$row['denominazione']}</option>";
                            }
                        ?>
                    </select>
                    <label for="idTipoPrestazione">Inserisci il tipo di prestazione</label>
                </div>
            </div>
            <div class="col col-auto">
                <button type="submit" class="btn btn-outline-secondary h-100">
                    <i class="bi bi-plus"></i>
                    Aggiungi alle prestazioni che offro
                </button>
            </div>
        </div>
    </form>
    <hr>
    <table class="table table-striped table-bordered table-hover mt-2">
        <thead class="table-light">
            <tr>
                <th scope="col">Denominazione</th>
                <th scope="col">Azioni</th>
            </tr>
        </thead>
        <tbody>
            <?php
                $res = $con->query(
                    "SELECT 
                        tipiPrestazione.denominazione, 
                        sociTipiPrestazione.idSocioTipoPrestazione
                    FROM 
                        sociTipiPrestazione, tipiPrestazione
                    WHERE 
                        idSocio = $idSocio AND
                        tipiPrestazione.idTipoPrestazione = sociTipiPrestazione.idTipoPrestazione
                    "
                );
                while($row = $res->fetch_assoc()){ ?>
                    <tr>
                        <td><?= $row['denominazione'] ?></td>
                        <td>
                            <a href='acc_tipi_prest.php?idRimozione=<?=$row['idSocioTipoPrestazione']?>' class='btn btn-outline-secondary'>
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