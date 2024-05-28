<?php

require_once 'fun.php';
check_session(false);

$error = '';

if(isset($_POST['email']) && isset($_POST['password'])){
    $email = $_POST['email'];
    $password = $_POST['password'];

    $stmt = $con->prepare('SELECT * FROM soci WHERE email = ?');
    $stmt->bind_param('s', $email);
    $stmt->execute();
    $result = $stmt->get_result();
    $stmt->close();

    if($result->num_rows == 1){
        $row = $result->fetch_assoc();
        if(password_verify($password, $row['password'])){
            if($row['sbloccato'] == '1'){
                $_SESSION['idSocio'] = $row['idSocio'];
                $_SESSION['nome'] = $row['nome'];
                $_SESSION['cognome'] = $row['cognome'];
                $_SESSION['email'] = $row['email'];
                $_SESSION['idZona'] = $row['idZona'];
                $groups = ['standard'];
                if($row['abilitatoSegreteria']){
                    $groups[] = 'segreteria';
                }
                $_SESSION['groups'] = $groups;
                header('Location: index.php');
                die();
            } else {
                $error = "Credenziali corrette, ma l'account è bloccato. Attendi l'approvazione come socio dalla segreteria.";
            }
        } else {
            $error = 'Email o password errati';
        }
    } else {
        $error = 'Email o password errati';
    }
}

page_start('Login');
?>

<div class="container">
    <div class="row justify-content-center">
        <div style="width: 400px; margin-top: 15%;">
            <center>
                <img src="icons/logo.png" alt="banca del tempo" height="150" style="margin-bottom: 10px;">
                <h3>Banca Del Tempo</h3>
            </center>
            <br>
            <form action="" method="post">
                <?php if($error != ''){ ?>
                    <div class="alert alert-danger" role="alert">
                        <?= $error ?>
                    </div>
                <?php } ?>
                <?php if (isset($_SESSION['regSucc'])) { ?>
                    <div class="alert alert-warning" role="alert">
                        Registrazione avvenuta con successo, attendi l'approvazione come socio dalla segreteria.
                    </div>
                <?php } ?>
                <div class="mb-3">
                    <input type="email" class="form-control" id="email" name="email" placeholder="Email" required>
                </div>
                <div class="mb-3">
                    <input type="password" class="form-control" id="password" name="password" placeholder="Password" required>
                </div>
                <button type="submit" class="btn btn-outline-secondary w-100 mb-3">Accedi</button> <br>
                <center>
                    <a href="register.php" class="alert-link">Registrati</a>
                </center>
            </form>
        </div>
    </div>
</div>

<?php 
page_end();