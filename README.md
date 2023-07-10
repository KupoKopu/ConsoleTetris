# ConsoleTetris
Console Tetris project for assignment

### Objective
- To create a tetris game as a console application.
- To demonstrate ability to implement design patterns
  - Singleton
- To demonstrate unit testing
- To demonstrate readable code



### Backlog

<del>00\
Console Rendering

<del>00.a\
As a Developer\
I want to be able to render characters in a fixed resolution


01\
Menu\
Has Play and Exit

01.a\
As a Player\
From the menu\
I want to be able to select play\
And expect Tetris gameplay to start

01.b\
As a Player\
From the menu\
I want to be able to select exit\
And expect the program to end

02\
Tetris Gameplay

02.a\
As a Player\
After selecting play\
I expect a 12x18 play area

02.b\
As a Player\
At the start of play\
I expect to see one of the 7 tetrinimos at the top

02.c\
As a Player\
I expect that the tetrinimo falls down

02.d\
As a Player\
I expect when the tetrinomo collides\
That the tetrinimo is "locked"

02.e\
As a Player\
I expect when I press A S D Q E\
That I move left, down, right and rotate left and right

0.2.f\
As a Player\
When the tetrinimo is "locked"\
And there is a full row\
I expect the line to disappear\
I expect the tetrinimos "locked" above to shift down\
And I expect to be awarded points (200)

0.2.g\
As a Player\
When the "locked" tetrinimos reaches the top of the play area\
I expect game over