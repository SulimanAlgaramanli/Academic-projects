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
     $query = "insert into playeruser ( userName ,password,email) VALUES ( '$user','$password','$email' ) ";
     $result = $conn->query($query);
    //close connection
    mysqli_close($conn);
    header ('Location: interface.php');
    }
    else
       echo ("error in the Password"); 
}
else
{
    echo "Error in validation" ;
}
 ?>



