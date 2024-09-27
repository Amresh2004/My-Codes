<?php
$f=$_GET['t1'];
$fp=fopen($f,"r");
$ch=$_GET['r'];//option name r
switch($ch)
{
case 1:
echo "Type of file: ".filetype($f);
break;
case 2:
echo "Last access time: ".date("F d Y H:i:s.",fileatime($f)); //day date year hr min seconds
break;
case 3:
echo "File size: ".filesize($f);
break;
case 4:
unlink($f);
if(!unlink($f))
{
echo "<br>Error deleting file";
}
else
{
echo "File deleted";
}
break;
}
?>