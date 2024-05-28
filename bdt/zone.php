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
        "text" => "Lista Zone",
        "icon" => "map",
        "active" => true
    ]
];

check_session(true, true);

page_start('Lista Zone');
T_navbar($breadcrumb);

?>

<main>
    <table class="table table-striped table-bordered table-hover">
        <thead class="table-light">
            <tr>
                <th>Denominazione</th>
                <th>Latitudine Inizio</th>
                <th>Longitudine Inizio</th>
                <th>Latitudine Fine</th>
                <th>Longitudine Fine</th>
                <th>Azioni</th>
            </tr>
        </thead>
        <tbody>
            <?php
            $res = $con->query("SELECT * FROM zone");
            while ($row = $res->fetch_assoc()) {
            ?>
                <tr>
                    <td><?php echo $row['denominazione']; ?></td>
                    <td><?php echo $row['lat_start']; ?></td>
                    <td><?php echo $row['lon_start']; ?></td>
                    <td><?php echo $row['lat_end']; ?></td>
                    <td><?php echo $row['lon_end']; ?></td>
                    <td>
                        <a class="btn btn-sm btn-outline-secondary" href="del_zona.php?id=<?php echo $row['idZona']; ?>">
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
