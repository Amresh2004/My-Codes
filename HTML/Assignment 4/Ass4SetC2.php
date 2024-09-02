<!DOCTYPE html>
<html>
<head>
    <title>Associative Array Operations</title>
</head>
<body>

<h2>Menu-Driven Associative Array Operations</h2>

<form method="post">
    <label>Choose an operation:</label><br><br>
    <select name="operation">
        <option value="chunk">Split an array into chunks</option>
        <option value="sortValues">Sort the array by values without changing keys</option>
        <option value="filterOdd">Filter the odd elements from an array</option>
        <option value="mergeArrays">Merge the given arrays</option>
        <option value="intersection">Find the intersection of two arrays</option>
        <option value="union">Find the union of two arrays</option>
        <option value="difference">Find the set difference of two arrays</option>
    </select><br><br>

    <label>Enter number of elements per chunk (only for chunk operation):</label><br>
    <input type="number" name="chunkSize"><br><br>

    <input type="submit" name="submit" value="Perform Operation">
</form>

<?php
// Example associative arrays
$array1 = array("a" => 1, "b" => 2, "c" => 3, "d" => 4, "e" => 5);
$array2 = array("c" => 3, "d" => 4, "e" => 5, "f" => 6, "g" => 7);

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $operation = $_POST['operation'];

    switch ($operation) {
        case "chunk":
            $chunkSize = $_POST['chunkSize'] ?? 2; // Default chunk size
            $chunks = array_chunk($array1, $chunkSize, true);
            echo "<h3>Array split into chunks:</h3>";
            echo "<pre>";
            print_r($chunks);
            echo "</pre>";
            break;

        case "sortValues":
            asort($array1);
            echo "<h3>Array sorted by values (keys unchanged):</h3>";
            echo "<pre>";
            print_r($array1);
            echo "</pre>";
            break;

        case "filterOdd":
            $filteredArray = array_filter($array1, function($value) {
                return $value % 2 !== 0;
            });
            echo "<h3>Filtered array with odd elements:</h3>";
            echo "<pre>";
            print_r($filteredArray);
            echo "</pre>";
            break;

        case "mergeArrays":
            $mergedArray = array_merge($array1, $array2);
            echo "<h3>Merged array:</h3>";
            echo "<pre>";
            print_r($mergedArray);
            echo "</pre>";
            break;

        case "intersection":
            $intersectionArray = array_intersect($array1, $array2);
            echo "<h3>Intersection of the arrays:</h3>";
            echo "<pre>";
            print_r($intersectionArray);
            echo "</pre>";
            break;

        case "union":
            $unionArray = $array1 + $array2; // Union of arrays with keys preserved
            echo "<h3>Union of the arrays:</h3>";
            echo "<pre>";
            print_r($unionArray);
            echo "</pre>";
            break;

        case "difference":
            $differenceArray = array_diff($array1, $array2);
            echo "<h3>Difference of the arrays (array1 - array2):</h3>";
            echo "<pre>";
            print_r($differenceArray);
            echo "</pre>";
            break;

        default:
            echo "<p>Invalid operation selected.</p>";
            break;
    }
}
?>

</body>
</html>
