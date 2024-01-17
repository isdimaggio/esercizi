<?php
$CONFIG = array(
    "DB_HOST"   => "localhost",
    "DB_USER"   => "root",
    "DB_PASS"   => "no >.<",
    "DB_NAME"   => "scratch"
);

$DB = new mysqli($CONFIG["DB_HOST"], $CONFIG["DB_USER"], $CONFIG["DB_PASS"], $CONFIG["DB_NAME"]);

// Check connection
if ($DB->connect_error) {
    die("Connection failed: " . $DB->connect_error);
}
