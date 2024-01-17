<?php
require_once "config.php";
require_once "AnagraficaModel.php";
require_once "PaginaLayout.php";

PaginaLayout::open("Eliminazione");
?> <center> <?php 
try {
    AnagraficaModel::delete($_POST['param']);
    ?> <span>Operazione completata con successo!</span> <br> <?php
} catch (\Throwable $th) {
    echo $th->getMessage();
}
PaginaLayout::navButton("./", "Indietro");
?> </center> <?php
PaginaLayout::close();