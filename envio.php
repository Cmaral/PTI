<?php
    // iot.php
    // Importamos la configuración
    require("conexion.php");
    // Leemos los valores que nos llegan por GET
    //$valor = mysqli_real_escape_string($con, $_GET['valor']);
    // Esta es la instrucción para insertar los valores
    $query = "INSERT INTO calor VALUES('2018-05-03 17:30:00', 26.00)";
    // Ejecutamos la instrucción
    mysqli_query($con, $query);
    mysqli_close($con);
?>