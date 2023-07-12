# ConsoleTetris
Console Tetris project for assignment

### Objective
- To create a tetris game as a console application.
- To demonstrate ability to implement design patterns
  - Singleton
  - Abstract factory
- To demonstrate unit testing
- To demonstrate readable code

### Challenge
To create a tetris game in which you start at the menu and choose to play.

You go through the tetris game play of randomly selected Tetrominos that will\
drop to the bottom of the playing field.

You will be able to move the Tetromino\
left, down, right and rotate clockwise to fit the pieces in aim of a line clear\
which is filling out a vertical line.

if the Tetrominos build up the top, you lose and are sent back to the menu to either quit or try again

This will require implementation of:
- event loops for real-time logic of falling Tetromino
- user Input for control of Tetromino movement
- code implementation to allow swapping of context (menu, tetris gameplay)
- rendering to display the game

My solution to this is to use C++ programming language\
with their standard library 'windows.h' to display on the Console.\
This is my choice as Tetris is not a game that requires a lot to display the type of gameplay it provides

I will approach this one by one developing the features such as rendering to console, the gameplay and then the menu.\
This will allow me to frequently run and debug the program as it's necessary to\
first be able to render the game and menu to see if it is behaving properly

### Breakdown

#### User Journey
1. start game
2. press play
3. use A S D to move left, down, right- use Q E to rotate left, rotate right
4. gameplay
   1. shapes spawn from top 
   2. shapes fall down
   3. align full row with (3.)
      1.  full row award points for row length
      2.  if full row and colour, award row length doubled.
   4.  end when column is filled
5.  back to menu
6.  press leaderboard
7.  see most recent at top
8.  go back
9.  press exit

#### Backlog

<del>00\
Console Rendering

<del>00.a\
As a Developer\
I want to be able to render characters in a fixed resolution

<del>01\
Menu\
Has Play and Exit

<del>01.a\
As a Player\
From the menu\
I want to be able to select play\
And expect Tetris gameplay to start

<del>01.b\
As a Player\
From the menu\
I want to be able to select exit\
And expect the program to end

<del>02\
Tetris Gameplay

<del>02.a\
As a Player\
After selecting play\
I expect a 12x18 play area

<del>02.b\
As a Player\
At the start of play\
I expect to see one of the 7 tetrinimos at the top

<del>02.c\
As a Player\
I expect that the tetrinimo falls down

<del>02.d\
As a Player\
I expect when the tetrinomo collides\
That the tetrinimo is "locked"\
And a new tetrinimo appears

<del>02.e\
As a Player\
I expect when I press left arrow,  down arrow, right arrow, z key\
That I move left, down, right and rotate (clockwise)

<del>0.2.f\
As a Player\
When the tetrinimo is "locked"\
And there is a full row\
I expect the line to disappear\
I expect the tetrinimos "locked" above to shift down\

<del>0.2.g\
As a Player\
When the "locked" tetrinimos reaches the top of the play area\
I expect game over

### Guidelines
Class structure (in order of list)
- methods
  - constructors
  - deconstructors
  - other methods
  - (private methods to public)
- fields 
  - constants
  - non-constants
  - (private fields to public)

Commonly used literals stored in constant.h as CONSTEXPR if possible\
Unpackage std::pairs wherever possible for readability\
Confusing literals like stored as variables named descriptively\
e.g. " ABCDEFG=#" as CHAR_ART

Classes, enums named in PascalCase.\
Constants named in uppercase SNAKE_CASE.\
Non-constants named in camelCase