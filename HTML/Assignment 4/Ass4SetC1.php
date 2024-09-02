<!DOCTYPE html>
<html>
<head>
    <title>Sort Associative Array</title>
</head>
<body>

<h2>Sorting an Associative Array</h2>

<?php
// Define the associative array
$people = array(
    "Sophia" => "31",
    "Jacob" => "41",
    "William" => "39",
    "Ramesh" => "40"
);

// a) Sort the array in ascending order by value
asort($people);
echo "<h3>Ascending Order by Value:</h3>";
foreach($people as $key => $value) {
    echo "$key: $value<br>";
}

// b) Sort the array in ascending order by key
ksort($people);
echo "<h3>Ascending Order by Key:</h3>";
foreach($people as $key => $value) {
    echo "$key: $value<br>";
}

// c) Sort the array in descending order by value
arsort($people);
echo "<h3>Descending Order by Value:</h3>";
foreach($people as $key => $value) {
    echo "$key: $value<br>";
}

// d) Sort the array in descending order by key
krsort($people);
echo "<h3>Descending Order by Key:</h3>";
foreach($people as $key => $value) {
    echo "$key: $value<br>";
}
?>

</body>
</html>
