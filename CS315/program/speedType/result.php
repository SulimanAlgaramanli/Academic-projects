<?php
session_start();

require_once 'dbConn.php';
$conn = new mysqli($hn, $un, $pw, $db);
     
     if ($conn->connect_error)
        die("Fatal Error");
    $query = "SELECT * FROM `printtext` where levelGame = 1 ORDER BY rand();";
    $result = $conn->query($query);
    $row = $result->fetch_array(MYSQLI_ASSOC);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Speed_Typeing</title>
    <link rel="stylesheet" href="file.css"  type="text/css">
    <script src="a.js" type="text/javascript"></script>
</head>
<body>


    <div class="header" style ="background-color: rgb(234, 199, 0);">
        <img     src="img/race.jpg" alt="car" id="img2" >
        <img    align="right" src="img/text.gif" alt="text" class="img1" >
    </div>
    <div class="nav" style="background-color: rgb(0, 0, 0); height: 30px ; color: white;">
        <table id="menu_bar">
        <tr>
         <th align="left"  style="color: white; font-size: 20px; width: 100%;">
        <?php echo( "Hi : ".$_SESSION['user']);
        ?></th>
        
         <th align="right"><a href="login.html" style="color: white; font-size: 20px;">Logout</a></th>
         </tr>
    </table>
    </div>

    your results :
    <p id="id_mist" style=" margin: 20px;"></p>
   

</body>
</html>

<?php
mysqli_close($conn);
?>