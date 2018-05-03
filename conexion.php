<?php
    // config.php
    // Credenciales
    $dbhost = "tutorial-db-instance.cy5t8ba5c4ju.us-west-2.rds.amazonaws.com";
    $dbuser = "pti20";
    $dbpass = "pti20pti20";
    $dbname = "meteo";
    // Conexión con la base de datos
    $con = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
?>