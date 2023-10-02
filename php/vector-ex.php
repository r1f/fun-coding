<!DOCTYPE html>
<html lang="en">

<head>
    <title></title>
</head>

<body>

<form method="get">
        <p>Return Y vector from N vector by the rules: Yi=Nj if Yi>0 and Yj=2Ni, if Yi"<"0 </p>
        <p>Find sequence numbers of positive elements</p>
        <label for="amount">Enter amount of elements: </label>
        <input type="number" name="amount">
        </br> 
        </br> 
        <input type="submit" value="Enter" name="submit">
    </form>
    <?php
    if (isset($_GET['submit']))
    {
        $amount = $_GET['amount'];
        $vectorN = array ();
        $vectorN = randomArray($vectorN, $amount);
        $vectorY = transformArray($vectorN);
        $positiveNum = positiveNum($vectorY);
        echo "<pre>";
        print_r($vectorN);
        echo "</pre>";
        echo "<pre>";
        print_r($vectorY);
        echo "</pre>";
        echo "<pre>";
        print_r($positiveNum);
        echo "</pre>";
    }

    function randomArray ($array, $amount)
    {
        for ($i=0; $i < $amount; $i++) 
        { 
            $array[$i] = rand(-100,100);
        }
        return $array;
    }

    function transformArray ($array)
    {
        for ($i=0; $i < count($array); $i++) 
        { 
            if ($array[$i]<0) 
            {
                $array[$i] = $array[$i] * 2; 
            }
        }
        return $array;
    }

    function positiveNum ($array)
    {
        $posArray = array();
        for ($i=0; $i < count($array); $i++) 
        { 
            if ($array[$i]>0) 
            {
                array_push($posArray, $i);
            }
        }
        return $posArray;
    }
    ?>
</body>
</html>