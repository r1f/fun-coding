<!DOCTYPE html>
<html lang="en">

<head>
    <title></title>
</head>

<body>

<form method="get">
        <label for="a1">Enter a1: </label>
        <input type="number" name="a1">
        </br> 
        </br> 
        <label for="a2">Enter a2: </label>
        <input type="number" name="a2">
        </br>
        </br> 
        <label for="b1">Enter b1: </label>
        <input type="number" name="b1">
        </br>
        </br> 
        <label for="b2">Enter b2: </label>
        <input type="number" name="b2">
        </br>
        </br> 
        <input type="submit" value="Enter" name="submit">
    </form>
    <?php
    if (isset($_GET['submit'])) 
    {
        $a1 = $_GET['a1'];
        $a2 = $_GET['a2'];
        $b1 = $_GET['b1'];
        $b2 = $_GET['b2'];
        $x=$a2*$b2/$b1;
        $y=$a1*$b1/$a2;
        if ($a1/$y==$a2/$b1 && $a2/$b1==$x/$b2 && $a1/$y==$x/$b2)
        {
            echo("Vectors are collinear");
        }
        else
        {
            $lengthX=sqrt(pow($a1,2)+pow($a2,2));
            $lengthY=sqrt(pow($b1,2)+pow($b2,2));
            echo("Vectors are not collinear");
            if($lengthX>$lengthY)
            {
                echo(" Vector Y shorter by ");
                echo($lengthX-$lengthY);
            }
            else
            {
                echo(" Vector X shorter by ");
                echo($lengthY-$lengthX);
            }
        }

    }
    ?>
</body>
</html>