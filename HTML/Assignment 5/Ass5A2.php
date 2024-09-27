<?php
$c=pg_connect("host=localhost dbname=amresh user=postgres password=8624807723");
if(!$c)
echo 'not connected';
else
echo "done \n";
$e=$_GET['t1'];
$query = "UPDATE comm 
          SET status = 'working' 
          WHERE C_No IN (SELECT C_No FROM comm WHERE C_No = '1')";

$result = pg_query($c, $query);

if (!$result) 
{
    echo "Error in Query...";
} 
else 
{
    echo "Update Successful!";
}
pg_close($c);
?>
