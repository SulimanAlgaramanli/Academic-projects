<?php

$user=$_GET['Username'];
$email=$_GET['email'];
$password=$_GET['password'];
$con_password=$_GET['Confirm_password'];

if($password==$con_password)
{
    echo "Username : ".$user."<br>";
    echo "Email : ".$email."<br>";
    echo "Password : ".$password."<br>";
    
}
else
    echo ("error in the Password");




?>
