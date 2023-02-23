# Wordle
We’ve been building our own Wordle game in class. Here’s what we agreed on for the base requirements:

Find out who is playing the game
Open a text file with words to use (maybe in /usr/share/dict ?)
Make a word list from those words (only 5 letters, no special chars)
Pick one word randomly
Read guesses on standard input (stdin) – but only give them 6 chances
Check if it’s actually a valid word, no uppercase, punctuation
Check if the letter is in the right spot, or at least in the word
Let user know which letters have already been used
Track which letters were wrong
Have some way of showing what was right/wrong, how many times guessed, how many left
Either print that they win or lose (with personalization, e.g., “You are terrible Matthew”)
Ask them if they want to play again

#Special Features
Your implementation of Wordle should have a unique special feature. Here are some of the ideas we came up with in class:

1. Stats (wins, losses, how many guesses, streaks) / previous results
  - Print to text file for bragging rights
2. Let user choose the size of the word
3. Use colors to indicate right, wrong, and “out of place”
4. Cowsay integration
5. Time limit
6. Do everything in C (no pre-generated word list)

# Documentation
You must explain how to build and run your program in your README.md file so that the course staff can play your Wordle and grade it.
