<!DOCTYPE html>
<html>
<head>
    <title>Spring Weather Analysis</title>
</head>
<body>

<?php
// Generate an array of 30 random high temperatures between 60°F and 85°F
$temperatures = array_map(function() {
    return rand(60, 85);
}, range(1, 30));

// Calculate the average high temperature
$averageTemp = array_sum($temperatures) / count($temperatures);

// Sort the temperatures to find the five warmest and coolest
sort($temperatures);
$coolestTemps = array_slice($temperatures, 0, 5);  // Five coolest temps
$warmestTemps = array_slice($temperatures, -5, 5); // Five warmest temps

// Display the results
echo "<h2>Spring Weather Analysis</h2>";
echo "<p><strong>Average High Temperature:</strong> " . round($averageTemp, 2) . "&deg;F</p>";
echo "<p><strong>Five Coolest High Temperatures:</strong> " . implode(", ", $coolestTemps) . "&deg;F</p>";
echo "<p><strong>Five Warmest High Temperatures:</strong> " . implode(", ", $warmestTemps) . "&deg;F</p>";
?>

</body>
</html>
