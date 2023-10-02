<!DOCTYPE html>
<html lang="en">

<head>
    <title></title>
</head>

<body>

<form method="get">
        <label for="valueAccuracy">Enter accuracy: </label>
        <input type="number" name="valueAccuracy"  step="any" >
        </br> 
        </br> 
        <input type="submit" value="Enter" name="submit">
    </form>
    <?php
    if (isset($_GET['submit']))
    {
        $valueAccuracy = floatval(urldecode($_GET['valueAccuracy']));
        $sum = accuracySum($valueAccuracy);
        echo($sum);
    }

    function accuracySum($accuracy)
    {
        $current = 0;
        $previous = 0;
        $sum = 0;
        $n = 1;
        do 
        {
            $previous=$current;
            $current = pow(-1,$n)/(3*pow($n,$n));
            $sum+=$current;
            $n++;
        } while (abs($current - $previous)>=$accuracy);
        return $sum;
    }
    ?>
</body>
</html>