


<?php
if (isset($_POST['submit'])) {
    $subjects = $_POST['subjects'];
    $totalMarks = 0;
    $totalSubjects = count($subjects);

    echo "<h2>Student Results</h2>";
    echo "<table border='1'>";
    echo "<tr><th>Serial No.</th><th>Subject Name</th><th>Marks</th></tr>";

    foreach ($subjects as $subject) {
        echo "<tr>";
        echo "<td>{$subject['serial']}</td>";
        echo "<td>{$subject['name']}</td>";
        echo "<td>{$subject['marks']}</td>";
        echo "</tr>";
        $totalMarks += $subject['marks'];
    }

    $percentage = $totalMarks / $totalSubjects;
    $grade = '';

    if ($percentage >= 90) {
        $grade = 'A';
    } elseif ($percentage >= 80) {
        $grade = 'B';
    } elseif ($percentage >= 70) {
        $grade = 'C';
    } elseif ($percentage >= 60) {
        $grade = 'D';
    } else {
        $grade = 'F';
    }

    echo "<tr><td colspan='2'>Total Marks</td><td>$totalMarks</td></tr>";
    echo "<tr><td colspan='2'>Percentage</td><td>$percentage%</td></tr>";
    echo "<tr><td colspan='2'>Grade</td><td>$grade</td></tr>";
    echo "</table>";
}
?>
