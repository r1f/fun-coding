<!DOCTYPE html>
<html lang="en">

<head>
    <title></title>
</head>

<body>

<form method="get">
        <p>Return sum and amount of matrix elements, which |values| are less than 1</p>
        <label for="columns">Enter amount of columns: </label>
        <input type="number" name="columns">
        </br> 
        </br> 
        <label for="rows">Enter amount of rows: </label>
        <input type="number" name="rows">
        </br> 
        </br> 
        <input type="submit" value="Enter" name="submit">
    </form>
    <?php
    if (isset($_GET['submit']))
    {
        $columns = $_GET['columns'];
        $rows = $_GET['rows'];
        $matrix = randomMatrix($columns, $rows);
        $countAndSum = countAndSum($matrix, $columns, $rows);
        printMatrix ($matrix, $columns, $rows);
        echo "<pre>";
        print_r($countAndSum);
        echo "</pre>";
    }

    function randomMatrix ($columns, $rows)
    {
        $matrix = array();
        for ($i=0; $i < $rows; $i++) 
        { 
            for ($j=0; $j < $columns; $j++) 
            { 
                $matrix[$i][$j] = rand(-20,20) / 10;
            }
        }
        return $matrix;
    }   

    function countAndSum ($matrix, $columns, $rows)
    {
        $countAndSum = array ();
        $count = 0;
        $sum = 0;
        for ($i=0; $i < $rows; $i++) 
        { 
            for ($j=0; $j < $columns; $j++) 
            { 
                if (abs($matrix[$i][$j]) < 1) 
                {
                    $count++;
                    $sum += $matrix[$i][$j];
                }
            }
        }
        array_push($countAndSum, "count", $count);
        array_push($countAndSum, "sum", $sum);
        return $countAndSum;
    }

    function printMatrix($matrix, $columns, $rows)
    {
        echo '<table style="border-spacing: 10px;"';
        for ($i = 0; $i < $rows; $i++)
        {
            echo '<tr>';
            for ($j=0; $j < $columns; $j++) 
            { 
                echo "<td>{$matrix[$i][$j]}\t</td>";
            }
            echo '</tr>';
        }
        echo '</table>';
    }
    ?>
</body>
</html>