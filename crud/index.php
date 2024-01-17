<?php
require_once "config.php";
require_once "AnagraficaModel.php";
require_once "PaginaLayout.php";

PaginaLayout::open("Anagrafica");
?>

<table class="table table-striped table-bordered">
    <thead>
        <tr>
            <td><b>ID</b></td>
            <td><b>Nome</b></td>
            <td><b>Cognome</b></td>
            <td><b>Data di nascita</b></td>
            <td style="width: 300px;"><b>Azioni</b></td>
        </tr>
    </thead>
    <tbody>
        <?php 
        $righe = AnagraficaModel::getAll();
        while ($riga = $righe->fetch_assoc()) { 
        ?>
        <tr>
            <td><?php echo $riga['idpersona'] ?></td>
            <td><?php echo $riga['nome'] ?></td>
            <td><?php echo $riga['cognome'] ?></td>
            <td><?php echo $riga['datanascita'] ?></td>
            <td>
                <?php PaginaLayout::navButton("edit.php", "Modifica", "primary", $riga['idpersona']); ?>
                <?php PaginaLayout::navButton("delete.php", "Elimina", "danger", $riga['idpersona']); ?>
            </td>
        </tr>
        <?php } ?>
    </tbody>
</table>

<center> <?php PaginaLayout::navButton("create.php", "Aggiungi"); ?> </center>
<?php PaginaLayout::close(); ?>