<h1 id="wordle">Wordle</h1>

<h4>Download Dictionary and cowsay using the following command</h4>

``` sudo pacman -Sy words ```
``` sudo pacman -Sy cowsay ```

<h4>Usage:</h4>

``` ./a.out /usr/share/dict/american-english [-l length_of_words] ```

<h5>Options:</h5>

* -l &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;length_of_words &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; User can deefine the length of word from 2 to 10 letters of word. Default length of word is 5.

\* Basically, the user is initially allowed five guesses, which corresponds to the default word length of five characters. If the user chooses to change the word length, the total number of guesses will be adjusted accordingly to match the new word length.

<h5>Example:</h5>

``` ./a.out /usr/share/dict/american-english -l 7 ```

<h4>Enter the user name </h4>

```bash
Please enter your name: #Please enter your name here
```

<h4>Start the game !</h4>

```bash 
Enter your guess :  #Please enter guess of word 
```

There are three different result for user's guess
1) Green Letter(O) : correct letter at the correct position
2) Yellow Letter(A) : correct letter but at incorrect position
3) Gray Letter(X) : wrong letter

// TODO :::: BUGS TO FIX

<h4>End of the game</h4>
If the user guesses correctly in given chances, the cow says "YOU WIN!"

``` _________ 
< YOU WIN >
 --------- 
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```
If the user loses, the correct answer will be shown.
```
// TODO :::: BUGS TO FIX

Unfortunately, the correct answer is [#answer], #username 
```

<h4>Play again</h4>
After the game, user can choose to continue to play or not.

```bash
Do you want to play again? [Y/N] :::: #user can enter Y or N
```

