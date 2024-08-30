<?php
    if (isset($_POST['submit'])) {
        $inputString = $_POST['inputString'];
        $separator = $_POST['separator'];
        $operation = $_POST['operation'];

        function splitString($str, $sep) {
            return explode($sep, $str);
        }

        function replaceSeparator($str, $oldSep, $newSep) {
            return str_replace($oldSep, $newSep, $str);
        }

        function findLastWord($str, $sep) {
            $lastOccurrence = strrchr($str, $sep);
            return $lastOccurrence ? substr($lastOccurrence, 1) : $str;
        }

        switch ($operation) {
            case 'split':
                $words = splitString($inputString, $separator);
                echo "Words after splitting: " . implode(", ", $words);
                break;

            case 'replace':
                $newSeparator = isset($_POST['newSeparator']) ? $_POST['newSeparator'] : '';
                if (!empty($newSeparator)) {
                    $replacedString = replaceSeparator($inputString, $separator, $newSeparator);
                    echo "String after replacing separator: " . $replacedString;
                } else {
                    echo "Please provide a new separator for replacement.";
                }
                break;

            case 'findLast':
                $lastWord = findLastWord($inputString, $separator);
                echo "The last word in the string is: " . $lastWord;
                break;

            default:
                echo "Please select a valid operation.";
        }
    }
    ?>