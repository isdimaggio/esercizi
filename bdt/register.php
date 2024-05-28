<?php

require_once 'fun.php';
check_session(false);

$error = '';

if ($_SERVER['REQUEST_METHOD'] == "POST"){
    if (
        isset($_POST['nome']) && 
        isset($_POST['cognome']) && 
        isset($_POST['dataNascita']) && 
        isset($_POST['email']) && 
        isset($_POST['numTelefono']) && 
        isset($_POST['idZona']) && 
        isset($_POST['indirizzo']) && 
        isset($_POST['password']) && 
        isset($_POST['password2'])
    ) {
        $nome = $_POST['nome'];
        $cognome = $_POST['cognome'];
        $dataNascita = $_POST['dataNascita'];
        $email = $_POST['email'];
        $numTelefono = $_POST['numTelefono'];
        $idZona = $_POST['idZona'];
        $indirizzo = $_POST['indirizzo'];
        $password = $_POST['password'];
        $password2 = $_POST['password2'];
    
        if ($password !== $password2) {
            $error = 'Le password non corrispondono';
        } else {
            $stmt = $con->prepare('SELECT * FROM soci WHERE email = ?');
            $stmt->bind_param('s', $email);
            $stmt->execute();
            $result = $stmt->get_result();
            $stmt->close();
    
            if ($result->num_rows == 0) {
                $stmt = $con->prepare(
                    'INSERT INTO soci 
                        (nome, cognome, dataNascita, email, numTelefono, idZona, indirizzo, password) 
                    VALUES 
                        (?, ?, ?, ?, ?, ?, ?, ?)'
                );
                $stmt->bind_param(
                    'ssssssss', 
                    $nome, $cognome, $dataNascita, $email, $numTelefono, $idZona, $indirizzo, 
                    password_hash($password, PASSWORD_DEFAULT)
                );
                $stmt->execute();
                $stmt->close();
    
                $_SESSION['regSucc'] = true;
                header('Location: login.php');
                die();
            } else {
                $error = 'Email già in uso';
            }
        }
    }else {
        $error = 'Compila tutti i campi';
    }
}

page_start('Registrazione');
?>

<div class="container">
    <div class="row">
        <div class="col-12 col-md-6 offset-md-3" style="margin-top: 50px;">
            <h1>Registrazione a Banca Del Tempo</h1>
            <form action="" method="post">
                <div class="row" style="margin-top: 50px;">
                    <div class="col col-6 mb-3">
                        <label for="nome">Nome</label>
                        <input type="text" class="form-control" id="nome" name="nome" required>
                    </div>
                    <div class="col col-6 mb-3">
                        <label for="cognome">Cognome</label>
                        <input type="text" class="form-control" id="cognome" name="cognome" required>
                    </div>
                </div>
                <div class="row">
                    <div class="col col-6 mb-3">
                        <label for="dataNascita">Data Di Nascita</label>
                        <input type="date" class="form-control" id="dataNascita" name="dataNascita" required>
                    </div>
                    <div class="col col-6 mb-3">
                        <label for="email">Email</label>
                        <input type="email" class="form-control" id="email" name="email" required>
                    </div>
                </div>
                <div class="row">
                    <div class="col col-6 mb-3">
                        <label for="numTelefono">Telefono</label>
                        <input type="tel" class="form-control" id="numTelefono" name="numTelefono" required>
                    </div>
                    <div class="col col-6 mb-3">
                        <label for="idZona">Zona</label>
                        <select class="form-select" id="idZona" name="idZona" required>
                            <option value="" selected disabled>Seleziona una zona</option>
                            <?php
                            $result = $con->query('SELECT * FROM zone');
                            while ($row = $result->fetch_assoc()) {
                                echo '<option value="' . $row['idZona'] . '">' . $row['denominazione'] . '</option>';
                            }
                            ?>
                        </select>
                    </div>
                </div>
                <div class="row">
                    <div class="col mb-3">
                        <label for="indirizzo">Indirizzo</label>
                        <input type="text" class="form-control" id="indirizzo" name="indirizzo" required>
                    </div>
                </div>
                <div class="row">
                    <div class="col col-6 mb-3">
                        <label for="password">Password</label>
                        <input type="password" class="form-control" id="password" name="password" minlength="8" required>
                    </div>
                    <div class="col col-6 mb-3">
                        <label for="password2">Conferma password</label>
                        <input type="password" class="form-control" id="password2" name="password2" minlength="8" required>
                    </div>
                </div>
                <div class="row">
                    <div class="col col-12 mb-3">
                        <label for="progress" style="margin-bottom: 5px;">Qualità password</label>
                        <div class="progress" role="progressbar" aria-valuenow="0" aria-valuemin="0" aria-valuemax="100" style="height: 25px">
                            <div class="progress-bar" id="progress-bar" style="width: 0%"></div>
                        </div>
                    </div>
                </div>
                <?php if($error != ''){ ?>
                    <div class="alert alert-danger" role="alert">
                        <?= $error ?>
                    </div>
                <?php } ?>
                <div class="row">
                    <div class="col col-auto">
                        <button type="submit" class="btn btn-secondary" style="padding-left: 20px; padding-right: 20px;">Registrati</button>
                    </div>
                    <div class="col w-100" style="text-align: right;">
                        <div style="margin-top: 10px;">
                            Hai già un account? <a href="login.php" class="alert-link">Login</a>
                        </div>
                    </div>
                </div>
            </form>
        </div>
    </div>
</div>

<script src="assets/passwordQuality.js"></script>

<?php
page_end();