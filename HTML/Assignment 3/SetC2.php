<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $bigString = $_POST['bigString'];
    $smallString = $_POST['smallString'];
    $position = (int)$_POST['position'];
    $numChars = (int)$_POST['numChars'];

    if (isset($_POST['delete'])) {
        // a. Delete a small part from the first string
        $result = substr_replace($bigString, '', $position, $numChars);
        echo "<p>After Deletion: $result</p>";
    }

    if (isset($_POST['insert'])) {
        // b. Insert the small string in the big string at the specified position
        $result = substr_replace($bigString, $smallString, $position, 0);
        echo "<p>After Insertion: $result</p>";
    }

    if (isset($_POST['replacePart'])) {
        // c. Replace some characters/words from the big string with the small string at specified position
        $result = substr_replace($bigString, $smallString, $position, $numChars);
        echo "<p>After Replacing Part: $result</p>";
    }

    if (isset($_POST['replaceAll'])) {
        // d. Replace all characters from the big string with the small string after a specified position
        $result = substr_replace($bigString, $smallString, $position);
        echo "<p>After Replacing All After Position: $result</p>";
    }
}
?>