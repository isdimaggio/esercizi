<?php
require_once 'fun.php';

check_session(true, true);

if(!isset($_GET['id'])){
    header('Location: soci.php');
    die();
}

$id = $con->real_escape_string($_GET['id']);

$con->query("UPDATE soci SET sbloccato = 1 WHERE idSocio = $id");
header('Location: soci.php');