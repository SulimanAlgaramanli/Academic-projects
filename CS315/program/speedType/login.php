<?php
$user = $_POST['Username'];
$password = $_POST['password'];
session_start();

if(!( $user=="" || $password=="" ))
{
  //connectToMySql.php
  require_once 'dbConn.php';
  $conn = new mysqli($hn, $un, $pw, $db);
  if ($conn->connect_error)
  {
    die("Fatal Error");
  }
  else
  {
    //echo "<p>Connected successfully.</p>";
  }
  $query = "SELECT * FROM playeruser where userName='$user' and  password='$password' ";
  $result = $conn->query($query);
  
  if ($result && $result->num_rows > 0)
  {  
    $_SESSION ['user'] = $user;
    header ('Location: interface.php');
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
    echo "Error in validation" ;
}
?>