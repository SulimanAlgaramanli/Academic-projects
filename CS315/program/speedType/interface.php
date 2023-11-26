<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Speed_Typeing</title>
    <link rel="stylesheet" href="file.css" type="text/css">
    
</head>
<body>
    <div id="contain">
        <div class="header" style ="background-color: rgb(234, 199, 0);">
            <img     src="img/race.jpg" alt="car" id="img2" >
            <img    align="right" src="img/text.gif" alt="text" class="img1" >
        </div>
        <div class="nav" style="background-color: rgb(0, 0, 0); height: 30px ; color: white;">
            <table id="menu_bar">
            <tr>
            <th align="left"  style="color: white; font-size: 20px; width: 100%;">
             <?php
             echo( "Hi : ".$_SESSION['user']);
             ?></th>
             <th align="right"><a href="login.html" style="color: white; font-size: 20px;">Logout</a></th>
             </tr>
        </table>
        </div>
        <div id="main2">
        
            <button  style="background-color: rgba(101, 60, 248, 0.836);  width: 150px ;  height: 80px ; font-size: 24px; " >
            <a href="play.php" style="color: rgba(0, 0, 0, 0.836);">Play</a></button>
        </div>
        <div id="footer">
            <span align="center" >CopyRight ©  2022</span> 
        </div>
    </div>
</body>
</html>