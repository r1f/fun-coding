<?php

$array = [4,3,2,1,7,5];

//Linear Search

function LinearSearch($array, $value)
{
    for ($i=0; $i < sizeof($array); $i++) 
    { 
        if ($array[$i]==$value) return $i;
    }
}

print_r($array);
echo("<br>");
echo ("Linear Search ".LinearSearch($array,7));
echo("<br>");

//Binary Search

sort($array);

function BinarySearch($array, $value)
{
    $first = array_key_first($array);
    $last = array_key_last($array);

    while ($first <= $last) 
    {
        $middle = intval(($first+$last)/2);

        if ($array[$middle] < $value) 
        {
            $first = $middle + 1;
        } 
        elseif ($array[$middle] > $value) 
        {
            $last = $middle - 1;
        } 
        else
        {
            return $middle;
        }
    }
    return null;
}

echo("<br>");
print_r($array);
echo("<br>");
echo ("Binary Search ".BinarySearch($array,7));
echo("<br>");
?>