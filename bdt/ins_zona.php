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
        "text" => "Inserisci Zona",
        "icon" => "geo-alt",
        "active" => true
    ]
];

check_session(true, true);
$NEEDS_LEAFLET = true;

if (isset($_POST['denominazione'])) {
    $denominazione = $con->real_escape_string($_POST['denominazione']);
    $latstart = $con->real_escape_string(round($_POST['latstart'], 6));
    $lonstart = $con->real_escape_string(round($_POST['lonstart'], 6));
    $latend = $con->real_escape_string(round($_POST['latend'], 6));
    $lonend = $con->real_escape_string(round($_POST['lonend'], 6));
    $con->query("INSERT INTO zone (denominazione, lat_start, lon_start, lat_end, lon_end) VALUES ('$denominazione', $latstart, $lonstart, $latend, $lonend)");
    header('Location: zone.php');
    exit;
}

page_start('Inserisci Zona');
T_navbar($breadcrumb);

?>

<main>
    <form action="" method="post">
        <div class="row mb-3">
            <div class="col" style="padding-right: 0px !important;">
                <div class="form-floating">
                    <input type="text" class="form-control" id="denominazione" name="denominazione" required>
                    <label for="denominazione" class="form-label">Denominazione</label>
                </div>
            </div>
            <div class="col col-auto">
                <button type="submit" class="btn btn-outline-secondary h-100">
                    <i class="bi bi-plus"></i>
                    Inserisci
                </button>
            </div>
        </div>
        <div class="row mb-3">
            <div class="col" style="padding-right: 0px !important;">
                <div class="form-floating">
                    <input type="text" class="form-control" id="latstart" name="latstart" required>
                    <label for="latstart" class="form-label">Latitudine Inizio</label>
                </div>
            </div>
            <div class="col">
                <div class="form-floating">
                    <input type="text" class="form-control" id="lonstart" name="lonstart" required>
                    <label for="lonstart" class="form-label">Longitudine Inizio</label>
                </div>
            </div>
        </div>
        <div class="row mb-3">
            <div class="col" style="padding-right: 0px !important;">
                <div class="form-floating">
                    <input type="text" class="form-control" id="latend" name="latend" required>
                    <label for="latend" class="form-label">Latitudine Fine</label>
                </div>
            </div>
            <div class="col">
                <div class="form-floating">
                    <input type="text" class="form-control" id="lonend" name="lonend" required>
                    <label for="lonend" class="form-label">Longitudine Fine</label>
                </div>
            </div>
        </div>
    </form>
    <div id='map'></div>
</main>

<script>
        // initialize map
        var map = L.map('map').setView([41.8, 12.5], 6);

        L.tileLayer('https://{s}.tile.osm.org/{z}/{x}/{y}.png', {
            attribution: '&copy; <a href="https://osm.org/copyright">OpenStreetMap</a> contributors'
        }).addTo(map);
        
        var areaSelect = L.areaSelect({
            width:40, 
            height:40, 
            //keepAspectRatio:true,
            //minHorizontalSpacing: 80,
            //minVerticalSpacing: 80,
        }); 

        areaSelect.on("change", function() {
            var bounds = this.getBounds();
            $("#latstart").val(bounds.getSouthWest().lat);
            $("#lonstart").val(bounds.getSouthWest().lng);
            $("#latend").val(bounds.getNorthEast().lat);
            $("#lonend").val(bounds.getNorthEast().lng);
        });

        areaSelect.addTo(map);

    </script>

<?php
page_end();
