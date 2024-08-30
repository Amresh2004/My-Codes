<?php
    if (isset($_POST['submit'])) {
        $largeString = $_POST['largeString'];
        $smallString = $_POST['smallString'];
        $operation = $_POST['operation'];

        function startsWith($large, $small) {
            $smallLen = strlen($small);
            return substr($large, 0, $smallLen) === $small;
        }

        function findPosition($large, $small) {
            return strpos($large, $small);
        }

        function compareStrings($large, $small, $n) {
            $largeSub = strtolower(substr($large, 0, $n));
            $smallSub = strtolower(substr($small, 0, $n));
            return strcmp($largeSub, $smallSub) === 0;
        }

        switch ($operation) {
            case 'startsWith':
                if (startsWith($largeString, $smallString)) {
                    echo "The small string appears at the start of the large string.";
                } else {
                    echo "The small string does not appear at the start of the large string.";
                }
                break;

            case 'findPosition':
                $position = findPosition($largeString, $smallString);
                if ($position !== false) {
                    echo "The small string is found at position: " . $position;
                } else {
                    echo "The small string is not found in the large string.";
                }
                break;

            case 'compareStrings':
                $n = isset($_POST['numChars']) ? intval($_POST['numChars']) : 0;
                if ($n > 0) {
                    if (compareStrings($largeString, $smallString, $n)) {
                        echo "The first $n characters of both strings are equal (case-insensitive).";
                    } else {
                        echo "The first $n characters of both strings are not equal (case-insensitive).";
                    }
                } else {
                    echo "Please enter a valid number of characters to compare.";
                }
                break;

            default:
                echo "Please select a valid operation.";
        }
    }
    ?>