<?php

    $user = $_POST['Username'];
    $password = $_POST['password'];

if(!($user==""||$password==""))
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
  
  $query = "SELECT * FROM user where user_name='$user' and user_password='$password' ";
  $result = $conn->query($query);
  
  if ($result && $result->num_rows > 0)
  {
      
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
              <h1 class="h3">The Grocery Store</h1>
              <p>
              A supermarket or central market is a complex or a multi-sectional building that may be multi-storey 
              in which the shopping, buying and selling of foodstuffs and household items such as: food, drink,
              and washing materials and tools, and may also contain sections for the sale of electronic devices, 
              tools and electrical machines
              </p>
          </div>
          <div id="footer">copyright 2022 grocery shop</div>
  
      </div>
  </body>
  </html>
  
  <?php
  }
  else
  {
      echo "<p>Unable to execute the query.</p> ". $conn -> error;
  }
  
  //close connection
  
  mysqli_close($conn);
  


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
    <title>Login</title>
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
            
            <table align="center" id="t1">
                <tr>
                    <th></th>
                    <th></th>
                    <th  align="center"><a href="register.html" style="color: rgb(46, 51, 34);">Sing up</a></th>
                </tr>
                <tr>
                <th colspan="2" align="center"><h1>Login</h1></th>
                </tr>
                <form method="post" action="login.php" >
                    <tr>
                        <td><label for="user">Username <span style="color: red;">*</span></label></td>
                    </tr>
                    <tr>
                        <td><input type="text" maxlength="40" id="user" name="Username" ></td>
                        
                    </tr>
                    <tr>
                        <td><label for="pass">Password <span style="color: red;">*</span></label></td>
                    </tr>
                    <tr>
                        <td><input type="password" maxlength="20" id="pass" name="password" ></td>
                        
                    </tr>
                    <tr>
                        <td colspan="2" align="center">
                            
                            <input type="submit" value="login" id="subm"
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