<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $email = $_POST['email'];

    // Explode the email by '@' symbol
    $parts = explode('@', $email);

    // a. Check if @ appears more than once
    if (count($parts) != 2) {
        echo "<p>Invalid email: @ symbol should appear exactly once.</p>";
    } else {
        $localPart = $parts[0];
        $domainPart = $parts[1];

        // b. Check the dot conditions before and after @
        if (preg_match('/^[^\.]*\.[^\.]*$/', $localPart)) {
            echo "<p>Invalid email: . should not appear more than once before @.</p>";
        } else {
            // c. Check if the substring before @ is valid
            if (preg_match('/^[^a-zA-Z]/', $localPart) || preg_match('/[^a-zA-Z0-9\.]/', $localPart)) {
                echo "<p>Invalid email: The local part should not begin with a digit, underscore, dot, or any special character.</p>";
            } else {
                // Validate the domain part after @
                $dotParts = explode('.', $domainPart);
                if (count($dotParts) < 2 || count($dotParts) > 3) {
                    echo "<p>Invalid email: The domain part should have at most two or at least one dot after @.</p>";
                } else {
                    echo "<p>Email is valid!</p>";
                }
            }
        }
    }
}
?>