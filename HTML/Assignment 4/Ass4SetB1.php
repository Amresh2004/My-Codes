<!DOCTYPE html>
<html>
<head>
    <title>Insert Item in Array</title>
</head>
<body>

<h2>Insert Item into Array at a Specified Position</h2>

<form method="post">
    <label>Enter the item to insert:</label><br>
    <input type="text" name="item" required><br><br>

    <label>Enter the position to insert the item (starting from 0):</label><br>
    <input type="number" name="position" required><br><br>

    <input type="submit" name="submit" value="Insert Item">
</form>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Initial array
    $array = array("Apple", "Banana", "Orange", "Mango", "Grapes");

    // Get the item and position from user input
    $item = $_POST['item'];
    $position = (int)$_POST['position'];

    // Insert the new item into the array at the specified position
    array_splice($array, $position, 0, $item);

    // Display the updated array
    echo "<h3>Updated Array:</h3>";
    echo "<pre>";
    print_r($array);
    echo "</pre>";
}
?>

</body>
</html>
