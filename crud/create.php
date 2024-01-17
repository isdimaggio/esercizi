<?php
require_once "config.php";
require_once "AnagraficaModel.php";
require_once "PaginaLayout.php";

PaginaLayout::open("Creazione");

if($_SERVER["REQUEST_METHOD"] == "POST"){
    ?> <center> <?php
    try {
        AnagraficaModel::create($_POST['nome'], $_POST['cognome'], $_POST['datanascita']);
        ?> <span class="mbb-10">Operazione completata con successo!</span> <br> <?php
    } catch (\Throwable $th) {
        echo $th->getMessage();
    }
    PaginaLayout::navButton("./", "Indietro");
    ?> </center> <?php
} else {
?>
<center>
    <form action="" method="post">
        <label for="nome">Nome:</label>
        <input type="text" name="nome" class="mbb-10" id="nome" required> <br>

        <label for="cognome">Cognome:</label>
        <input type="text" name="cognome" id="cognome" class="mbb-10" required> <br>

        <label for="datanascita">Data di nascita:</label>
        <input type="date" name="datanascita" id="datanascita" class="mbb-10" required> <br>
        
        <button type="submit" class="btn btn-success mbb-10">Inserisci</button> <br>
    </form>

    <?php PaginaLayout::navButton("./", "Indietro"); ?>
</center>
<?php }