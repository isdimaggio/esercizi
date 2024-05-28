<?php
require_once 'fun.php';

check_session(true, true);

if(!isset($_GET['id'])){
    header('Location: zone.php');
    die();
}

$id = $con->real_escape_string($_GET['id']);

$con->query("DELETE FROM zone WHERE idZona = $id");
header('Location: zone.php');