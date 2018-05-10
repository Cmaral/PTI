<?php
    // Importamos la configuración
    require("conexion.php");

	date_default_timezone_set('Europe/Madrid');
    $date = date('Y/m/d H:i:s', time());
    $value = (int)$argv[1];
    echo $date;
    echo $value;
    $query = "INSERT INTO lluvia VALUES('$date', '$value')";

    mysqli_query($con, $query);
    mysqli_close($con);
?>
