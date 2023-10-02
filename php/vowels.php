<!DOCTYPE html>
<html lang="en">

<head>
    <title></title>
</head>

<body>

    <form method="get">
        <p>Return amount of vowels, if amount less than 5 to add vowel after every consonant</p>
        <label for="str">Enter a string: </label>
        <input type="text" name="str">
        </br> 
        </br> 
        <input type="submit" value="Enter" name="submit">
    </form>
    <?php
    if (isset($_GET['submit']))
    {
        $str = $_GET['str'];
        $vowels = array ('a','e','i','o','u','A','E','I','O','U');
        $words = explode(" ", $str);
        $vowelCount = vowelCount($words);
        $editWords = editWords($words, $vowelCount);
        $outputArray = array(
            $words,
            $vowelCount,
            $editWords
        );
        echo "<pre>";
        printMatrix($outputArray);
        echo "</pre>";
    }

    function printMatrix($matrix)
    {
        echo '<table style="border-spacing: 10px;"';
        for ($i = 0; $i < count($matrix); $i++)
        {
            echo '<tr>';
            for ($j=0; $j < 3; $j++) 
            { 
                echo "<td>{$matrix[$i][$j]}\t</td>";
            }
            echo '</tr>';
        }
        echo '</table>';
    }

    function vowelCount($words)
    {
        global $vowels;
        $vowelCount = array ();
        for ($i=0; $i < count($words); $i++) 
        { 
            $count = 0;
            for ($j=0; $j < strlen($words[$i]); $j++) 
            { 
                if (in_array($words[$i][$j], $vowels))
                {
                    $count++;
                }
            }
            array_push($vowelCount, $count);
        }
        return $vowelCount;
    }

    function editWords($words, $vowelCount)
    {
        global $vowels;
        $editedWords = array ();
        for ($i=0; $i < count($words); $i++) 
        { 
            $buffs = null;
            if ($vowelCount[$i]<5) 
            {
                for ($j=0; $j < strlen($words[$i]); $j++) 
                { 
                    $buff = null;
                    if(!in_array($words[$i][$j], $vowels))
                    {
                        $buff = $words[$i][$j] . $vowels[array_rand($vowels)];
                    }
                    if ($buff == null) 
                    {
                        $buffs.=$words[$i][$j];
                    }
                    else
                    {
                        $buffs.=$buff;
                    }
                }
                array_push($editedWords,$buffs);
            }
            else
            {
                array_push($editedWords,$words[$i]);
            }
        }
        return $editedWords;
    }
    ?>
</body>
</html>