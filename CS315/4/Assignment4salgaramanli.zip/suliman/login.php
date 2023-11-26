
<?php

$user=$_POST['Username'];
$password=$_POST['password'];
If($user=="sa" && $password=="sa")
{
     //echo "Username:" .$user ."<br>"."password:". $password ;
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
        <div id="header"><img  class="img_head"  src="img/market.jpg" alt="SuperMarket"  ></div>
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

} else
     echo "error"; 

?>