<!DOCTYPE html>
<html>
<body>
<?php
$filenm="item.dat";
$fp=fopen($filenm,'r');
?>
<centre>
<table border=2>
<?php
echo"<br><tr><th> item no</th><th> item name</th><th>unit sold</th><th>rate</th><th>total amt</th></tr></br>";
while(!feof($fp))
{
$x=explode(" ",fgets($fp));
$t=$x[2]*$x[3];
echo "<tr><td>$x[0]</td><td>$x[1]</td><td>$x[2]</td><td>$x[3]</td><td>$t</td></tr>";
}
?>
</table>
</centre>
</body>
</html>