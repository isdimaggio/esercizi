<?php
require_once 'fun.php';

check_session(true);

if(!isset($_GET['id'])){
    header('Location: /');
    die();
}

$id = $con->real_escape_string($_GET['id']);
$prestazione = $con->query("SELECT * FROM prestazioni WHERE idPrestazione = $id")->fetch_assoc();

if ($_SESSION['idSocio'] == $prestazione['idSocioPrestante'] ){
    $con->query("UPDATE prestazioni SET stato = 'annullataPrestante' WHERE idPrestazione = $id");
} else if ($_SESSION['idSocio'] == $prestazione['idSocioRicevente']){
    $con->query("UPDATE prestazioni SET stato = 'annullataRicevente' WHERE idPrestazione = $id");
}
header('Location: /?success=2');