<!DOCTYPE html>
<html lang="en">

<head>
    <title></title>
</head>

<body>

<form method="get">
        <label for="circleX">Enter x: </label>
        <input type="number" name="circleX">
        </br> 
        </br> 
        <label for="circleY">Enter y: </label>
        <input type="number" name="circleY">
        </br>
        </br> 
        <label for="radius">Enter the radius: </label>
        <input type="number" name="radius">
        </br>
        </br> 
        <label for="pointX">Enter x: </label>
        <input type="number" name="pointX">
        </br>
        </br> 
        <label for="pointY">Enter y: </label>
        <input type="number" name="pointY">
        </br>
        </br>
        <input type="submit" value="Enter" name="submit">
    </form>
    <?php
    if (isset($_GET['submit'])) 
    {
        $circleX = $_GET['circleX'];
        $circleY = $_GET['circleY'];
        $radius = $_GET['radius'];
        $pointX = $_GET['pointX'];
        $pointY = $_GET['pointY'];
        $distance=sqrt((pow(($pointX-$circleX),2) - pow(($pointY-$circleY),2)));
        if ($radius==(pow(($pointX-$circleX),2) - pow(($pointY-$circleY),2)))
        {
            echo ("The point lies on the circle");
        }
        elseif ($distance<$radius)
        {
            echo ("The point lies inside the circle");
        }
        else 
        {
            echo ("The point lies outside the circle");
        }
    }
    ?>
</body>
</html>