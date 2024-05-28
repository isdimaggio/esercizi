<?php
require_once 'fun.php';

check_session(true, true);

if(!isset($_GET['id'])){
    header('Location: tipi_prestazione.php');
    die();
}

$id = $con->real_escape_string($_GET['id']);

$con->query("DELETE FROM tipiPrestazione WHERE idTipoPrestazione = $id");
header('Location: tipi_prestazione.php');