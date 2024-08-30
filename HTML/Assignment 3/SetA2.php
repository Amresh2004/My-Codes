<?php
    if (isset($_POST['submit'])) {
        $inputString = $_POST['inputString'];
        $operation = $_POST['operation'];

        function findLength($str) {
            $length = 0;
            while (isset($str[$length])) {
                $length++;
            }
            return $length;
        }

        function countVowels($str) {
            $vowels = 0;
            $str = strtolower($str);
            $len = findLength($str);
            for ($i = 0; $i < $len; $i++) {
                if (in_array($str[$i], ['a', 'e', 'i', 'o', 'u'])) {
                    $vowels++;
                }
            }
            return $vowels;
        }

        function convertToTitleCase($str) {
            $str = strtolower($str);
            $words = explode(' ', $str);
            foreach ($words as &$word) {
                $word = ucfirst($word);
            }
            return implode(' ', $words);
        }

        function padString($str) {
            return "*" . $str . "*";
        }

        function trimString($str) {
            $i = 0;
            while (isset($str[$i]) && $str[$i] == ' ') {
                $i++;
            }
            return substr($str, $i);
        }

        switch ($operation) {
            case 'length':
                echo "Length of the string: " . findLength($inputString);
                break;
            case 'vowels':
                echo "Total number of vowels: " . countVowels($inputString);
                break;
            case 'titlecase':
                echo "String in Title Case: " . convertToTitleCase($inputString);
                break;
            case 'pad':
                echo "Padded String: " . padString($inputString);
                break;
            case 'trim':
                echo "String after trimming leading whitespaces: " . trimString($inputString);
                break;
            case 'reverse':
                echo "Reversed String: " . strrev($inputString);
                break;
            default:
                echo "Please select a valid operation.";
        }
    }
    ?>