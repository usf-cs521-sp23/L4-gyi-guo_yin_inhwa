<h1 id="wordle">Wordle</h1>
<p><em>Create your GitHub repo for this lab here:</em> <a href="https://classroom.github.com/a/NPWEj2Uw">https://classroom.github.com/a/NPWEj2Uw</a></p>
<p>We&rsquo;ve been building our own Wordle game in class. Here&rsquo;s what we agreed on for the base requirements:</p>
<ol>
<li>Find out who is playing the game</li>
<li>Open a text file with words to use (maybe in /usr/share/dict ?)
<ul>
<li>Make a word list from those words (only 5 letters, no special chars)</li>
</ul>
</li>
<li>Pick one word randomly</li>
<li>Read guesses on standard input (stdin) &ndash; but only give them 6 chances
<ul>
<li>Check if it&rsquo;s actually a valid word, no uppercase, punctuation</li>
<li>Check if the letter is in the right spot, or at least in the word</li>
</ul>
</li>
<li>Let user know which letters have already been used
<ul>
<li>Track which letters were wrong</li>
</ul>
</li>
<li>Have some way of showing what was right/wrong, how many times guessed, how many left</li>
<li>Either print that they win or lose (with personalization, e.g., &ldquo;You are terrible Matthew&rdquo;)</li>
<li>Ask them if they want to play again</li>
</ol>
<h2 id="special-features">Special Features</h2>
<p>Your implementation of Wordle should have a unique special feature. Here are some of the ideas we came up with in class:</p>
<ol>
<li>Stats (wins, losses, how many guesses, streaks) / previous results
<ul>
<li>Print to text file for bragging rights</li>
</ul>
</li>
<li>Let user choose the size of the word</li>
<li>Use colors to indicate right, wrong, and &ldquo;out of place&rdquo;</li>
<li>Cowsay integration</li>
<li>Time limit</li>
<li>Do everything in C (no pre-generated word list)</li>
</ol>
<h2 id="documentation">Documentation</h2>
<p>You <strong>must</strong> explain how to build and run your program in your README.md file so that the course staff can play your Wordle and grade it.</p>

