<?php
require_once 'fun.php';
require_once 'navbar.php';

$breadcrumb = [
    [
        "link" => "",
        "text" => "Gestione",
        "icon" => "gear",
        "active" => false
    ],
    [
        "link" => "",
        "text" => "Gestione Soci",
        "icon" => "people",
        "active" => true
    ]
];

check_session(true, true);

page_start('Gestione Soci');
T_navbar($breadcrumb);

$query = 
"SELECT
    soci.idSocio,
    soci.nome,
    soci.cognome,
    soci.email,
    soci.numTelefono,
    zone.denominazione,
    soci.abilitatoSegreteria,
    soci.sbloccato
FROM
    soci,
    zone
WHERE
    soci.idZona = zone.idZona
";

?>

<main>
    <table class="table table-striped table-bordered table-hover">
        <thead class="table-light">
            <tr>
                <th>Nome</th>
                <th>Cognome</th>
                <th>Email</th>
                <th>Telefono</th>
                <th>Zona</th>
                <th>Operazioni</th>
            </tr>
        </thead>
        <tbody>
            <?php
            $res = $con->query($query);
            while ($row = $res->fetch_assoc()) {
            ?>
                <tr>
                    <td><?php echo $row['nome']; ?></td>
                    <td><?php echo $row['cognome']; ?></td>
                    <td><?php echo $row['email']; ?></td>
                    <td><?php echo $row['numTelefono']; ?></td>
                    <td><?php echo $row['denominazione']; ?></td>
                    <td>
                        <a class="btn btn-sm btn-outline-secondary" href="del_socio.php?id=<?php echo $row['idSocio']; ?>">
                            <i class="bi bi-trash"></i>
                            Elimina
                        </a>
                        <a class="btn btn-sm btn-outline-secondary" href="reset_pass.php?id=<?php echo $row['idSocio']; ?>">
                            <i class="bi bi-key"></i>
                            Reset Password
                        </a>
                        <?php 
                        if ($row['sbloccato'] == 0) {
                            ?>
                            <a class="btn btn-sm btn-outline-secondary" href="sblocca_socio.php?id=<?php echo $row['idSocio']; ?>">
                                <i class="bi bi-unlock"></i>
                                Ammetti Nuovo Socio
                            </a>
                        <?php
                        } else {
                            if ($row['abilitatoSegreteria'] == "false") {
                                ?>
                                <a class="btn btn-sm btn-outline-secondary" href="seg_socio.php?en=true&id=<?php echo $row['idSocio']; ?>">
                                    <i class="bi bi-check2-all"></i>
                                    Abilita Segreteria
                                </a>
                            <?php
                            } else {
                                ?>
                                <a class="btn btn-sm btn-outline-secondary" href="seg_socio.php?en=false&id=<?php echo $row['idSocio']; ?>">
                                    <i class="bi bi-x-lg"></i>
                                    Disabilita Segreteria
                                </a>
                            <?php
                            }
                        ?>
                    </td>
                </tr>
            <?php
            }
        }
        ?>
        </tbody>
    </table>
</main>

<?php
page_end();
