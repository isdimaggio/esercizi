<?php
class PaginaLayout
{

    /**
     * Apre la pagina
     * @param pageTitle<string> Titolo della pagina
     * @return void
     */
    public static function open($pageTitle){
        ?>
        <!DOCTYPE html>
        <html lang="it">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" 
                integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">
            <title>Esercizio CRUD: <?php echo $pageTitle ?> </title>
            <style>
                .padding {
                    padding: 20px 20px 20px 20px;
                }

                .mbb-10 {
                    margin-bottom: 10px;
                }
            </style>
        </head>
        <body class="padding">
            <center style="margin-bottom: 10px;">
                <h3><?php echo $pageTitle ?></h3>
            </center>
        <?php
    }

    /**
     * Chiude la pagina
     * @return void
     */
    public static function close() {
        ?>
        </body>
        </html>
        <?php
    }

    /**
     * Crea un bottone di navigazione
     * @param page<string> URL della pagina a cui navigare.
     * @param text<string> Testo del bottone
     * @param class<string> Classe del pulsante (colore) ['primary', 'secondary', ...] quelle di bootstrap
     * @param parameter<string> Se popolato (opzionale) trasforma la richiesta in una POST e invia quel valore aggiuntivo
     * @return void
     */
    public static function navButton($page, $text, $class = "secondary", $parameter = "") {
        ?>
        <form action="<?php echo $page ?>" method="<?php echo $parameter == "" ? "get" : "post" ?>" style="display: inline;">
            <?php if($parameter != "") { ?>
                <input type="hidden" name="param" value="<?php echo $parameter  ?>">
            <?php } ?>
            <button type="submit" class="btn btn-<?php echo $class ?>">
                <?php echo $text ?>
            </button>
        </form>
        <?php
    }
}