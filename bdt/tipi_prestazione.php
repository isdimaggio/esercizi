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
        "text" => "Gestione tipi prestazione",
        "icon" => "wrench-adjustable-circle",
        "active" => true
    ]
];

check_session(true, true);

if (isset($_POST['denominazione'])) {
    $denominazione = $con->real_escape_string($_POST['denominazione']);
    $con->query("INSERT INTO tipiPrestazione (denominazione) VALUES ('$denominazione')");
}

page_start('Gestione tipi prestazione');
T_navbar($breadcrumb);

?>

<main>
    <form action="" method="post">
        <div class="row">
            <div class="col" style="padding-right: 0px !important;">
                <div class="form-floating">
                    <input type="text" class="form-control" id="denominazione" name="denominazione" required>
                    <label for="denominazione" class="form-label">Denominazione</label>
                </div>
            </div>
            <div class="col col-auto">
                <button type="submit" class="btn btn-outline-secondary h-100">
                    <i class="bi bi-plus"></i>
                    Aggiungi
                </button>
            </div>
        </div>
    </form>
    <hr class="">
    <table class="table table-striped table-bordered w-100">
        <thead>
            <tr>
                <th>ID</th>
                <th>Denominazione</th>
                <th>Operazioni</th>
            </tr>
        </thead>
        <tbody>
            <?php
            $res = $con->query("SELECT * FROM tipiPrestazione");
            while ($row = $res->fetch_assoc()) {
            ?>
                <tr>
                    <td><?= $row['idTipoPrestazione'] ?></td>
                    <td><?= $row['denominazione'] ?></td>
                    <td>
                        <a class="btn btn-outline-secondary" href="del_tipi_prest.php?id=<?= $row['idTipoPrestazione'] ?>">
                            <i class="bi bi-trash"></i>
                            Elimina
                        </a>
                    </td>
                </tr>
            <?php
            }
            ?>
        </tbody>
    </table>
</main>

<?php
page_end();
