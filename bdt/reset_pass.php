<?php
require_once 'fun.php';

check_session(true, true);

if(!isset($_GET['id'])){
    header('Location: soci.php');
    die();
}

$id = $con->real_escape_string($_GET['id']);
$socio = $con->query("SELECT nome, cognome, email FROM soci WHERE idSocio = $id")->fetch_assoc();
$pass = randomPassword(8);
$hash = password_hash(
    $pass, 
    PASSWORD_DEFAULT
);

$con->query("UPDATE soci SET password = '$hash' WHERE idSocio = $id");

page_start('Password resettata');
?>

<main>
    <center>
    <br>
    <br>
    <br>
    <br>
    <div class="alert alert-success" role="alert" style="width: 350px;">
        Reset andato a buon fine! <br> 
        Socio: <b> <?= $socio['nome'] . " " . $socio['cognome'] ?> </b> <br>
        Email: <b> <?= $socio['email'] ?> </b> <br>
        Nuova password: <b> <?= $pass ?> </b> <br>
        <div class="noprint mt-2">
            <button class="btn btn-outline-secondary" onclick="window.print()">
                <i class="bi bi-printer"></i>
                Stampa
            </button> 
            <a href="soci.php" class="btn btn-outline-secondary">
                <i class="bi bi-arrow-left"></i>
                Indietro
            </a>
        </div>
    </div>
    </center>
</main>

<?php
page_end();
