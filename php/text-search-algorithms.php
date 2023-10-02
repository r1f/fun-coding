<?php

// Direct Search Algorithm

function DirectSearch ($subString, $string)
{
    $count = 0;

    for ($i=0; $i < strlen($string); $i++) 
    {
        $buffI = $i;

        for ($j=0; $j < strlen($subString); $j++) 
        { 
            if ($string[$i]==$subString[$j])
            {
                $count++;
                $i++;
            }
            if ($count==strlen($subString))
                return true;
        }

        $count = 0;
        $i = $buffI;
    }
    return false;
}

echo(DirectSearch("abcabd", "abcabcaabcabd"));
echo("<br>");

// Knuth-Morris-Pratt Algorithm

function KnuthMorrisPrattAlgorithm($subString, $string)
{
    for ($i=0; $i < strlen($string);) 
    { 
        for ($j=0; $j < strlen($subString); $j++) 
        { 
            if ($string[$i]==$subString[$j])
            {
                $i = IsCorrect($i, $string, $subString);            
                if (is_bool($i)) return true;
            }
            else
            {
                $i++;
            }
            break;
        }
    }
    return false;
}

function IsCorrect($indexOfString, $string, $subString)
{
    if(strlen($string)-$indexOfString < strlen($subString))
    {
        return $indexOfString + 1;
    }

    $count = 0;
    for ($i = $indexOfString; $i < $indexOfString + strlen($subString); $i++) 
    { 
        for ($j=0; $j < strlen($subString); $j++) 
        { 
            if ($string[$i] == $subString[$j]) 
            {
                $count++;
                $i++;
            }
            else break;

            if($count == strlen($subString)) return true;
        }
        $indexOfString = $i;
        return $indexOfString;
    }
}

echo(KnuthMorrisPrattAlgorithm("abcabd", "abcabcaabcabd"));
echo("<br>");

// Boyer–Moore algorithm

function BoyerMooreAlgorithm($text, $pattern)
{
    $badMatchTable = BadMatchTable($pattern);

    for ($i=strlen($pattern) - 1; $i < strlen($text);) 
    { 
        $count = 0;
        $k = $i;
        for ($j = strlen($pattern) - 1; $j >= 0; $j--) 
        {
            if ($pattern[$j] == $text[$k]) 
            {
                $count++;
            }
            else
            {
                if (str_contains($pattern, $text[$k])) 
                {
                    $i += $badMatchTable[strpos($pattern, $text[$k])];
                    break;
                }
                else
                {
                    $i += end($badMatchTable);
                    break;
                }
            }
            if ($count == strlen($pattern)) return true;
            $k--;
        }
    }

    return null;
}

function BadMatchTable($pattern)
{
    $patternReversed = strrev($pattern);
    $matchTable = [strlen($patternReversed)];

    for ($i=1; $i < strlen($patternReversed); $i++) 
    { 
        array_push($matchTable, $i);
    }

    $matchTable = UpdateArray($patternReversed, $matchTable);
    return $matchTable;
}

function UpdateArray($pattern, $array)
{
    for ($i = 0; $i < sizeof($array); $i++) 
    { 
        for ($j=$i+1; $j < sizeof($array); $j++) 
        { 
            if ($pattern[$i]==$pattern[$j]) 
            {
                $array[$j] = $array[$i];
            }
        }
    }
    return array_reverse($array);
}

echo(BoyerMooreAlgorithm("abcafdfabcabd", "abcabd"));
?>