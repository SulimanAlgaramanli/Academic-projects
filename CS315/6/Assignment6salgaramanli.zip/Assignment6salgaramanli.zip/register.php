<?php

$user = $_POST['Username'];
$email = $_POST['email'];
$password = $_POST['password'];
$con_password = $_POST['Confirm_password'];
if(!($user==""||$email==""||$password==""||$con_password==""))
{
    if ($password==$con_password)

    {
    
     //connectToMySql.php
    
     require_once 'dbConn.php';
    
     $conn = new mysqli($hn, $un, $pw, $db);
     
     if ($conn->connect_error)
        die("Fatal Error");
     
     else
     
     {
     //echo "<p>Connected successfully.</p>";
     }
     
     $query = "insert into user ( user_name ,user_password,user_emailAddress) VALUES ( '$user','$password','$email' ) ";
     $result = $conn->query($query);
    //close connection
    
    mysqli_close($conn);
    
    
    ?>
    
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Suliman algaramanli</title>
        <link rel="stylesheet" href="main.css" type="text/css">
    </head>
    <body>
        <div class="contenar">
            <div id="header"><img  class="img_head"  src="img/market.jpg" alt="SuperMarket"  id="img1" ></div>
            <div id="nav">
                <table id="menu_bar">
                <tr>
                <th ><a href="index.html">Home</a></th>
                 <th ><a href="order.html">Order</a></th>
                 <th ><a href="about.html">About Us</a></th>
                 <th ><a href="price.html">Prices</a></th>
                 <th id="contact"><a href="contact.html">Contact Us</a></th>
                 
            </table></div>
            <div id="sidebar">
                <img src="img/3.jpg">
                <img src="img/2.jpg">
                <img src="img/1.jpg">            
            </div>
            <div id="main"> 
                <h1 class="h1">grocery shop in Tripoli</h1>
                
                <?php
                     echo "Username : ".$user."<br>";
                     echo "Email : ".$email."<br>";
                     echo "Password : ".$password."<br>";
                     
                ?>
              
            </div>
            <div id="footer">copyright 2022 grocery shop</div>
    
        </div>
    </body>
    </html>
    
    <?php   
    }
    else
        echo ("error in the Password");
   
}
else
{
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Regiseration</title>
    <link rel="stylesheet" href="main.css" type="text/css">
</head>
<body>
    <div class="contenar">
        <div id="header"><img  class="img_head"  src="img/market.jpg" alt="SuperMarket"  id="img1"></div>
        <div id="nav">
            <table id="menu_bar">
            <tr>
             <th >Home</th>
             <th >Order</th>
             <th >About Us</th>
             <th >Prices</th>
             <th id="contact">Contact Us</th>
             
        </table></div>
        <div id="sidebar">
            <img src="img/3.jpg">
            <img src="img/2.jpg">
            <img src="img/1.jpg">            
        </div>
        <div id="main"> 
            <h1 class="h1">grocery shop in Tripoli</h1>
            
            <table  align="center" id="t1">
                <tr>
                    <th></th>
                    <th></th>
                    <th  align="center"><a href="login.html" style="color: rgb(46, 51, 34);">Login</a></th>
                </tr>
                <tr>
                <th colspan="2" align="center"><h1>Regiseration</h1></th>
                </tr>
                <form method="post" action="register.php">
                    <tr>
                        <td><label for="user">Username <span style="color: red;">*</span></label></td>
                    </tr>
                    <tr>
                        <td><input type="text" maxlength="40" id="user" name="Username" ></td>
                        
                    </tr>
                    <tr>
                        <td><label for="em">Email <span style="color: red;">*</span></label></td>
                    </tr>
                    <tr>
                        <td><input type="text" maxlength="40" id="em" name="email" ></td>
                        
                    </tr>
                    <tr>
                        <td><label for="pass">Password<span style="color: red;">*</span> </label></td>
                    </tr>
                    <tr>
                        <td><input type="password" maxlength="20" id="pass" name="password" ></td>
                        
                    </tr>
                    <tr>
                        <td><label for="con_pass">Confirm Password <span style="color: red;">*</span></label></td>
                    </tr>
                    <tr>
                        <td><input type="password" maxlength="20" id="con_pass" name="Confirm_password" ></td>
                        
                    </tr>
                    <tr>
                        <td colspan="2" align="center">
                            <input type="submit" value="Sign up" id="subm"
                            style="background-color: rgb(206, 195, 44); width: 110px;  "/> 
                        </td>
                    </tr>
                </form>
            </table>

        </div>
        <div id="footer">copyright 2022 grocery shop</div>

    </div>            
</body>
</html>


<?php
}
 ?>



