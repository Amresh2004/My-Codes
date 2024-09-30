<?php

    $f = $_GET['t1'];
    $ch = $_GET['r']; // option name r

    if (file_exists($f)) {
        switch ($ch) {
            case 1:
                echo "Type of file: " . filetype($f);
                break;
            case 2:
                echo "Last access time: " . date("F d Y H:i:s.", fileatime($f)); // day date year hr min seconds
                break;
            case 3:
                echo "File size: " . filesize($f) . " bytes";
                break;
            case 4:
                if (unlink($f)) {
                    echo "File deleted successfully.";
                } else {
                    echo "<br>Error deleting file";
                }
                break;
            default:
                echo "Invalid choice.";
        }
    }
     else {
        echo "File does not exist.";
    }
?>
