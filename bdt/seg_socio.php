<?php
require_once 'fun.php';

check_session(true, true);

if(!isset($_GET['id'])){
    header('Location: soci.php');
    die();
}

$en = "false";
if(isset($_GET['en'])){
    $en = $con->real_escape_string($_GET['en']);
}

$id = $con->real_escape_string($_GET['id']);

$con->query("UPDATE soci SET abilitatoSegreteria = '$en' WHERE idSocio = $id");
header('Location: soci.php');