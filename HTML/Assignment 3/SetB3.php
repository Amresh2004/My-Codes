<?php
    if (isset($_POST['submit'])) {
        $studentName = isset($_POST['studentName']) ? $_POST['studentName'] : null;
        $collegeName = isset($_POST['collegeName']) ? $_POST['collegeName'] : null;
        $greetingMessage = isset($_POST['greetingMessage']) ? $_POST['greetingMessage'] : null;

        function generateGreeting($studentName = null, $collegeName = null, $greetingMessage = null) {
            if (!$studentName) {
                $studentName = "Dear Student";
            }
            if (!$collegeName) {
                $collegeName = "Your College";
            }
            if (!$greetingMessage) {
                $greetingMessage = "Welcome to a new academic year!";
            }

            return "{$greetingMessage} {$studentName} from {$collegeName}.";
        }

        echo generateGreeting($studentName, $collegeName, $greetingMessage);
    }
    ?>