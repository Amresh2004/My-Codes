<!DOCTYPE html>
<html>
<head>
    <title>Array Search</title>
</head>
<body>

<h2>Search for a Value in an Array</h2>

<form method="post">
    <label>Enter the value to search:</label><br>
    <input type="text" name="searchValue" required><br><br>

    <input type="submit" name="submit" value="Search">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Define an array with some values
    $array = array("Apple", "Banana", "Orange", "Mango", "Grapes", "Banana");

    // Get the value to search for from user input
    $searchValue = $_POST['searchValue'];

    // Initialize an array to store matching indices
    $matchingIndices = [];

    // Search for the value in the array
    foreach ($array as $index => $value) {
        if ($value === $searchValue) {
            $matchingIndices[] = $index;
        }
    }

    // Display the results
    if (!empty($matchingIndices)) {
        echo "<p>Value '$searchValue' found at the following positions: " . implode(", ", $matchingIndices) . "</p>";
    } else {
        echo "<p>Value '$searchValue' not found in the array.</p>";
    }
}
?>

</body>
</html>
