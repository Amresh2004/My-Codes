<?php
if(file_exists('item.dat'))
{

	$f=fopen('item.dat','r');
	echo"<br><br>";
	echo"<table border type=3 align=center>";
	echo"<tr><td align=center>Item Code</td>";
	echo"<td align=center>Item Name</td>";
	echo"<td align=center>Unit Sold</td>";
	echo"<td align=center>Rate</td>";
	
    while(!feof($f))
	{
	  $d=fgets($f);
	  $s=explode(' ',$d);
	 if(!empty($s[0]) && !empty($s[1]) && !empty($s[2]) && !empty($s[3]))
{
      echo"<tr><td align=center>$s[0]</td>"; 
      echo"<td align=center>$s[1]</td>";
      echo"<td align=center>$s[2]</td>";
      echo"<td align=center>$s[3]</td>";

}
}
echo"</table>";
}
?>
