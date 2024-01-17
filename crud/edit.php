<?php
require_once "config.php";
require_once "AnagraficaModel.php";
require_once "PaginaLayout.php";

PaginaLayout::open("Modifica");

if($_SERVER["REQUEST_METHOD"] == "POST"){
    if(isset($_POST['param'])){
        $person = AnagraficaModel::getOne($_POST["param"]);
        ?>
        <center>
            <form action="" method="post">
                <input type="hidden" name="id" id="id" value="<?php echo $person['idpersona'] ?>">

                <label for="nome">Nome:</label>
                <input type="text" name="nome" class="mbb-10" id="nome" value="<?php echo $person['nome'] ?>" required> <br>

                <label for="cognome">Cognome:</label>
                <input type="text" name="cognome" id="cognome" class="mbb-10" value="<?php echo $person['cognome'] ?>" required> <br>

                <label for="datanascita">Data di nascita:</label>
                <input type="date" name="datanascita" id="datanascita" class="mbb-10" value="<?php echo $person['datanascita'] ?>" required> <br>
                
                <button type="submit" class="btn btn-success mbb-10">Applica</button> <br>
            </form>
            <?php PaginaLayout::navButton("./", "Annulla"); ?>
        </center>
        <?php 
    } else {
        ?> <center> <?php 
        try {
            AnagraficaModel::update($_POST['id'], $_POST['nome'], $_POST['cognome'], $_POST['datanascita']);
            ?> <span>Operazione completata con successo!</span> <br> <?php
        } catch (\Throwable $th) {
            echo $th->getMessage();
        }
        PaginaLayout::navButton("./", "Indietro");
        ?> </center> <?php
        PaginaLayout::close();
    }
}