<!DOCTYPE html>
<html lang="en">

<head>
    <title></title>
</head>

<body>

<form method="get">
        <label for="pointX">Enter x: </label>
        <input type="number" name="pointX">
        </br> 
        </br> 
        <label for="pointY">Enter y: </label>
        <input type="number" name="pointY">
        </br>
        </br> 
        <label for="pointX1">Enter x: </label>
        <input type="number" name="pointX1">
        </br>
        </br> 
        <label for="pointY1">Enter y: </label>
        <input type="number" name="pointY1">
        </br>
        </br> 
        <label for="pointX2">Enter x: </label>
        <input type="number" name="pointX2">
        </br>
        </br>
        <label for="pointY2">Enter y: </label>
        <input type="number" name="pointY2">
        </br>
        </br>
        <input type="submit" value="Enter" name="submit">
    </form>
    <?php
    if (isset($_GET['submit'])) 
    {
        $pointX = $_GET['pointX'];
        $pointY = $_GET['pointY'];
        $pointX1 = $_GET['pointX1'];
        $pointY1 = $_GET['pointY1'];
        $pointX2 = $_GET['pointX2'];
        $pointY2 = $_GET['pointY2'];
        if (($pointY-$pointY1)*($pointX-$pointX2)==($pointY-$pointY2)*($pointX-$pointX1))
        {
            echo ("Points are on the same line");
        }
        else
        {
            $AB=sqrt(pow(($pointX-$pointX1),2)+pow(($pointY-$pointY1),2));
            $AC=sqrt(pow(($pointX-$pointX2),2)+pow(($pointY-$pointY2),2));
            $BC=sqrt(pow(($pointX1-$pointX2),2)+pow(($pointY1-$pointY2),2));
            $perimeter=$AB+$AC+$BC;
            $halfPerimeter=$perimeter/2;
            $square=sqrt($halfPerimeter*($halfPerimeter-$AB)*($halfPerimeter-$AC)*($halfPerimeter-$BC));
            echo("Perimeter ");
            echo($perimeter);
            echo("Square ");
            echo($square);
        }
    }
    ?>
</body>

</html>