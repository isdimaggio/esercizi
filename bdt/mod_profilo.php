<?php
require_once 'fun.php';
require_once 'navbar.php';

$breadcrumb = [
    [
        "link" => "",
        "text" => "Modifica Profilo",
        "icon" => "person-fill-gear",
        "active" => true
    ]
];

$idSocio = $_SESSION['idSocio'];

if (isset($_POST['indirizzo']) && isset($_POST['email']) && isset($_POST['numTelefono']) && isset($_POST['idZona'])) {
    $indirizzo = $con->real_escape_string($_POST['indirizzo']);
    $email = $con->real_escape_string($_POST['email']);
    $numTelefono = $con->real_escape_string($_POST['numTelefono']);
    $idZona = $con->real_escape_string($_POST['idZona']);

    $con->query("UPDATE soci SET indirizzo = '$indirizzo', email = '$email', numTelefono = '$numTelefono', idZona = $idZona WHERE idSocio = $idSocio");
    header("Location: mod_profilo.php");
    exit();
}

// ottieni informazioni attuali
$result = $con->query("SELECT * FROM soci WHERE idSocio = $idSocio");
$row = $result->fetch_assoc();

$indirizzo = $row['indirizzo'];
$email = $row['email'];
$numTelefono = $row['numTelefono'];
$idZona = $row['idZona'];

check_session();
page_start('Modifica Profilo');
T_navbar($breadcrumb);
?>

<main>
    <form action="" method="post">
        <div class="row">
            <div class="col col-6 mb-3">
                <label for="indirizzo">Indirizzo</label>
                <input type="text" class="form-control" id="indirizzo" name="indirizzo" value="<?= $indirizzo ?>" required>
            </div>
            <div class="col col-6 mb-3">
                <label for="email">Email</label>
                <input type="email" class="form-control" id="email" name="email" value="<?= $email ?>" required>
            </div>
        </div>
        <div class="row">
            <div class="col col-6 mb-3">
                <label for="numTelefono">Telefono</label>
                <input type="tel" class="form-control" id="numTelefono" name="numTelefono" value="<?= $numTelefono ?>" required>
            </div>
            <div class="col col-6 mb-3">
                <label for="idZona">Zona</label>
                <select class="form-select" id="idZona" name="idZona" required>
                    <option value="" selected disabled>Seleziona una zona</option>
                    <?php
                    $result = $con->query('SELECT * FROM zone');
                    while ($row = $result->fetch_assoc()) {
                        $selected = $row['idZona'] == $idZona ? 'selected' : '';
                        echo '<option ' . $selected . ' value="' . $row['idZona'] . '">' . $row['denominazione'] . '</option>';
                    }
                    ?>
                </select>
            </div>
        </div>
        <center>
            <button type="submit" class="btn btn-secondary mt-2">
                <i class="bi bi-floppy"></i>
                Salva modifiche
            </button>
        </center>
    </form>
</main>

<?php
page_end();
