<?php
require_once 'fun.php';
require_once 'navbar.php';

$breadcrumb = [
    [
        "link" => "",
        "text" => "Cambio Password",
        "icon" => "key",
        "active" => true
    ]
];

$idSocio = $_SESSION['idSocio'];

if (isset($_POST['oldPassword']) && isset($_POST['newPassword']) && isset($_POST['confermaPassword'])) {
    $oldPassword = $con->real_escape_string($_POST['oldPassword']);
    $newPassword = $con->real_escape_string($_POST['newPassword']);
    $confermaPassword = $con->real_escape_string($_POST['confermaPassword']);

    $result = $con->query("SELECT password FROM soci WHERE idSocio = $idSocio");
    $row = $result->fetch_assoc();
    $password = $row['password'];

    if (password_verify($oldPassword, $password) && $newPassword === $confermaPassword) {
        $newPassword = password_hash($newPassword, PASSWORD_DEFAULT);
        $con->query("UPDATE soci SET password = '$newPassword' WHERE idSocio = $idSocio");
        header("Location: /");
        exit();
    } else {
        $err = '<div class="alert alert-danger" role="alert">Password errata</div>';
    }
}

check_session();
page_start('Cambio Password');
T_navbar($breadcrumb);
?>

<main>
    <form action="" method="post">
        <div class="flex-col mt-5">
            <div class="col col-4">
                <?= $err ?? '' ?>
            </div>
            <div class="col col-4 mb-3">
                <label for="oldPassword">Vecchia Password</label>
                <input type="password" class="form-control" id="oldPassword" name="oldPassword" required>
            </div>
            <div class="col col-4 mb-3">
                <label for="newPassword">Nuova Password</label>
                <input type="password" class="form-control" id="password" name="newPassword" required>
            </div>
            <div class="col col-4 mb-3">
                <label for="confirmPassword">Conferma Password</label>
                <input type="password" class="form-control" id="password2" name="confermaPassword" required>
            </div>
            <div class="col col-4 mb-3">
                <label for="progress" style="margin-bottom: 5px;">Qualità password</label>
                <div class="progress" role="progressbar" aria-valuenow="0" aria-valuemin="0" aria-valuemax="100" style="height: 25px">
                    <div class="progress-bar" id="progress-bar" style="width: 0%"></div>
                </div>
            </div>
        </div>
        <center>
            <button type="submit" id="tastoSubmit" class="btn btn-secondary mt-2" disabled>
                <i class="bi bi-floppy"></i>
                Le password non corrispondono...
            </button>
        </center>
    </form>

    <script src="assets/passwordQuality.js"></script>

    <script>
        const password = document.getElementById('password');
        const password2 = document.getElementById('password2');
        const submit = document.getElementById('tastoSubmit');

        password2.addEventListener('input', () => {
            if (password.value === password2.value) {
                submit.disabled = false;
                submit.innerHTML = '<i class="bi bi-floppy"></i> Salva modifiche';
            } else {
                submit.disabled = true;
                submit.innerHTML = '<i class="bi bi-floppy"></i> Le password non corrispondono...';
            }
        });
    </script>
</main>

<?php
page_end();
