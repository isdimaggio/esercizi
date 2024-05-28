<?php
require_once 'fun.php';

if(!isset($_SESSION['idSocio'])){
    http_response_code(403);
    die();
}

if(!isset($_GET['id'])){
    http_response_code(400);
    die();
}

$id = $con->real_escape_string($_GET['id']);
$socio = $con->query("SELECT nome, cognome, email, numTelefono, indirizzo FROM soci WHERE idSocio = $id")->fetch_assoc();

if($socio == null){
    http_response_code(404);
    die();
}

echo json_encode($socio);