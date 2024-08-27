<?php
function findMod($num1, $num2) {
    return $num1 % $num2;
}

function findPower($num1, $num2) {
    return pow($num1, $num2);
}

function sumFirstN($num1) {
    return ($num1 * ($num1 + 1)) / 2;
}

function findFactorial($num2) {
    $factorial = 1;
    for ($i = 1; $i <= $num2; $i++) {
        $factorial *= $i;
    }
    return $factorial;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $num1 = $_POST['num1'];
    $num2 = $_POST['num2'];

    echo "Results:<br>";
    echo "Modulus of $num1 and $num2: " . findMod($num1, $num2) . "<br>";
    echo "$num1 raised to the power of $num2: " . findPower($num1, $num2) . "<br>";
    echo "Sum of the first $num1 numbers: " . sumFirstN($num1) . "<br>";
    echo "Factorial of $num2: " . findFactorial($num2) . "<br>";
}
?>
