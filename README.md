<h1 id="wordle">Wordle</h1>

### Download Dictionary and cowsay using the following command

``` sudo pacman -Sy words ```

``` sudo pacman -Sy cowsay ```

### Usage:

``` ./a.out /usr/share/dict/american-english [-l length_of_words] ```

#### Options:

* -l &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;length_of_words &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; User can deefine the length of word from 2 to 10 letters of word. Default length of word is 5.

\* Basically, the user is initially allowed five guesses, which corresponds to the default word length of five characters. If the user chooses to change the word length, the total number of guesses will be adjusted accordingly to match the new word length.

#### Example:

``` ./a.out /usr/share/dict/american-english -l 7 ```

### Enter the user name

```bash
Please enter your name: #Please enter your name here
```

### Start the game !

```bash 
Enter your guess :  #Please enter guess of word 
```

There are three different result for user's guess
1) Green Letter(O) : correct letter at the correct position
2) Yellow Letter(A) : correct letter but at incorrect position
3) Gray Letter(X) : wrong letter

// TODO :::: BUGS TO FIX

### End of the game
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

### Play again
After the game, user can choose to continue to play or not.

```bash
Do you want to play again? [Y/N] :::: #user can enter Y or N
```

