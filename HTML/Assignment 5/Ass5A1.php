<?php
$f=$_GET['t1'];
$fp=fopen($f,'r');
$fs=filesize($f);
echo fread($fp,$fs);
echo " <br>"."filesize is ".$fs;
?>