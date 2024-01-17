<?php
// CREATE TABLE `Anagrafica` (`idpersona` INT NOT NULL , `nome` VARCHAR(50) NOT NULL , `cognome` VARCHAR(50) NOT NULL , `datanascita` DATE NOT NULL );
class AnagraficaModel {

    /**
     * Crea una nuova entry nel database per la tabella Anagrafica
     * @param nome<string> Nome della persona.
     * @param cognome<string> Cognome della persona.
     * @param datanascita<string> Data di nascita in formato AAAA-MM-GG.
     * @return void
     */
    public static function create($nome, $cognome, $datanascita){
        global $DB;

        // ripulisci input
        $nome = $DB->real_escape_string(htmlspecialchars($nome));
        $cognome = $DB->real_escape_string(htmlspecialchars($cognome));
        $datanascita = $DB->real_escape_string($datanascita);

        // input validation
        if(trim($nome) == "") throw new Exception("Campo nome mancante", 1);
        if(trim($cognome) == "") throw new Exception("Campo cognome mancante", 2);
        if(trim($datanascita) == "") throw new Exception("Campo data di nascita mancante", 3);

        $DB->query("INSERT INTO `Anagrafica` (`nome`, `cognome`, `datanascita`) VALUES ('$nome', '$cognome', '$datanascita')");

        if($DB->errno != 0) throw new Exception("Errore MySQL: ". $DB->error, $DB->errno);
    }

    /**
     * Modifica una entry nella tabella Anagrafica
     * @param id<string> Id del record da modificare
     * @param nome<string> Nome della persona.
     * @param cognome<string> Cognome della persona.
     * @param datanascita<string> Data di nascita in formato AAAA-MM-GG.
     * @return void
     */
    public static function update($id, $nome, $cognome, $datanascita){
        global $DB;

        // ripulisci input
        $id = $DB->real_escape_string(htmlspecialchars($id));
        $nome = $DB->real_escape_string(htmlspecialchars($nome));
        $cognome = $DB->real_escape_string(htmlspecialchars($cognome));
        $datanascita = $DB->real_escape_string($datanascita);

        // input validation
        if(trim($id) == "") throw new Exception("Campo id mancante", 1);
        if(trim($nome) == "") throw new Exception("Campo nome mancante", 1);
        if(trim($cognome) == "") throw new Exception("Campo cognome mancante", 2);
        if(trim($datanascita) == "") throw new Exception("Campo data di nascita mancante", 3);

        $DB->query("UPDATE `Anagrafica` SET `nome` = '$nome', `cognome` = '$cognome', `datanascita` = '$datanascita' WHERE `Anagrafica`.`idpersona` = $id");

        if($DB->errno != 0) throw new Exception("Errore MySQL: ". $DB->error, $DB->errno);
    }

    /**
     * Seleziona tutti i record della tabella
     * @return mysqli_result
     */
    public static function getAll(){
        global $DB;

        $res = $DB->query("SELECT * FROM `Anagrafica`");
        if(!$res) throw new Exception("Errore MySQL: ". $DB->error, $DB->errno);

        return $res;
    }

    /**
     * Seleziona solo un record
     * @param id<int> id del record
     * @return array Array con i field "idpersona", "nome", "cognome" e "datanascita"
     */
    public static function getOne($id){
        global $DB;

        $id = $DB->real_escape_string($id);
        $res = $DB->query("SELECT * FROM `Anagrafica` WHERE `idpersona` = $id");

        // controllo errori
        if(!$res) throw new Exception("Errore MySQL: ". $DB->error, $DB->errno);
        if($res->num_rows != 1) throw new Exception("Record non trovato", 4);
        
        return $res->fetch_assoc();
    }

    /**
     * Elimina un record
     * @param id<int> id del record
     * @return void
     */
    public static function delete($id){
        global $DB;

        $id = $DB->real_escape_string($id);
        $res = $DB->query("DELETE FROM `Anagrafica` WHERE `idpersona` = $id");

        // controllo errori
        if(!$res) throw new Exception("Errore MySQL: ". $DB->error, $DB->errno);
    }

}
