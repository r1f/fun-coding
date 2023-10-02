<!DOCTYPE html>
<html lang="en">

<head>
    <title></title>
</head>

<body>

<form method="get">
        <p>Return perfect numbers from a range</p>
        <label for="EndOfRange">Enter the end of range: </label>
        <input type="number" name="EndOfRange">
        </br> 
        </br> 
        <input type="submit" value="Enter" name="submit">
    </form>
    <?php
    if (isset($_GET['submit']))
    {
        $EndOfRange = $_GET['EndOfRange'];
        $values = array ();
        $values = perfectNumbers($EndOfRange, $values);
        echo "<pre>";
        print_r($values);
        echo "</pre>";
    }

    function perfectNumbers($EndOfRange, $values)
    {
        for ($i=1; $i <= $EndOfRange; $i++) 
        { 
            $dividers = array();
            for ($j=1; $j < $i; $j++) 
            { 
                if ($i % $j == 0)
                {
                    array_push($dividers, $j);
                }
            }
            if (array_sum($dividers)==$i) 
            {
                array_push($values, $i);
            }
        }
        return $values;
    }
    ?>
</body>
</html>