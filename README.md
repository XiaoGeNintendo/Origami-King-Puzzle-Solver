# Origami-King-Puzzle-Solver
Paper Mario Origami King Battle Puzzle Solver For Myself

# Purpose
To solve the battle puzzles in Paper Mario: Origami King because the author is a dumba*s.

It's for regular small-fry battles. It can solve a 4*12 puzzle and the search depth is 3 moves.

# Building & Modification
Really easy to build, just open your `g++` and compile it.

You can modify the code to increase search depth. But the code doesn't really include many optimization so its performance is extremely poor.

# Introduction
I wrote it in <1h and it was poorly written.

I wrote it in Competitve Programming style.

# Usage

~~Please see code~~

Create a file called puzzle.txt. Then put 4 lines, each line contains 12 digits 0/1. 0=no enemy, 1=has enemy. Don't put spaces between them.

Each line represents a circle. The lines at the bottom represent inner circles and the lines at the top represent outer circles.

For example, 

![Pic](https://www.nintendo.com/content/dam/noa/en_US/games/switch/p/paper-mario-the-origami-king-switch/screenshot-gallery/paper-mario-the-origami-king-switch-screenshot03.jpg)

can be represented as 

```
000001000000
000001000000
001101000000
001101000000
```

Run the program and it will show one result. Press any key except E to show another one. Press E to end.
