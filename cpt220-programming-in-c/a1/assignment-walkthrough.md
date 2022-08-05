# Assignment 1 Walk Through
* Part 2 is a half way submission point.
* Some part so of the program need no work, like `main.c`
  * Functions for the game are dasiy chained, staring from here.
* Deadline at 9pm isn't hard, an hour or so is fine. 6 hours no.


## TODO
* MAP OUT HOW EVERY FILE INTERACTS IN A DIAGRAM
* **Read the discussion board**
* Learn how backgammon works.
* Use the test harness as you develop. **This is your mark to aim for**
* Use the requirements to make sure you have covered everything.
  * Validate moves is huge amount of marks.

## Source Code Walk Through
* rules has been updated with more comments.
  * This is where most of our work is done.
* Pass the same seed number in for testing.
* One player goes clockwise, and the other counter-clockwise.
  * Once they have all their pieces in their corner, they can remove them from the board.
  * The print function should handle both directions.

### Headers
* How do headers work?
  * The assignment structure is defined by header files.
  * `SHARED_H` is imported into every module / file.
  * Header files are use to share information with the rest of the program. **THESE ARE BRIDGES BETWEEN SOURCE FILES!**
    * Anything local should be inside the `.c` file.
    * `player.h` includes `io.h` and thus anything in `player.c` can use functions inside of `io.h` **that have a function prototype there**.
* What happens when I include a file that includes other files?
  * All other files are copied in.
  * `game.h` includes a lot of other header files that are brought in whenever this header file is included elsewhere.
    * Use an include guard to stop the multiple loading of header files and subsequently data structures. `#ifndef SOME_HEADER` is the include guard.
    * `rules.h` has an example of declaring a struct pointer without assigning anything, another `c` file will set this up.
    * Including the same header file to itself is a infinite loop and the compiler will give up.
* `gcc -E header-file.h` will show you what he pre-processor does to the header file. Like including all the libraries, expanding enums, etc.
* Each `.c` file is compiled separately and the `.h` defines what will be published but this compilation.

### Program Structure
* The parts of the program are set up similarly to OOP classes.
  * Each `.c` is basically a class.
  * In C we needed to be explicit about passing in pointers so you can manipulate each struct. Like in Java with `this`. `player_int(struct player* ...)` is an example of this.
* The player `struct`s will point to the array of players.
  * All player data will be inside the player pointers inside this array.

### Game Data structure
* `board` is a 2d array, of `enum` `piece`.
  * The values that can be entered are defined in the `enum`.
  * Use the constant names, not numbers.
* Each game piece is in the 2d array.
  * Need to map player's input to the array offset. E.g. minus 1.

### `io.h`
* Has the board colours.
  * Use the `enum` constants to print colours. `color[COLOR_RED]` for example.
* `extern` means it is declared elsewhere.
* The numbers on the board need to be printed by you.
  * They change between players, but stay the same the whole game. Don't need to save these, calculate them from the array indices.
  * 14 high and 12 across.

## Player Order
* Use `rand` to roll 2 die and see who goes first.
  * If they are the same, roll again.
  * Highest role goes first and is coloured white, is X, and goes clockwise around the board.
    * The other player is the opposite.

## Player Turns
* The pointer to the current game is passed into the player. It is stored there and can be used throughout the game.
* Player can roll 2 die and then enter their move.
  * Doubles mean you can move four times. To 2 x 3's would mean 3 x 4 in total, 12 moves.
* Total moves must be less than or equal to the die rolls.
  * Expected rules are in the `a1spec` file. The key stuff is in the requirements.
* Cannot move onto a column where an opponent has 2 or more pieces. And can only go in one direction. Can't remove pieces until all pieces are in the corner (1-6).
* `12:3` means move the piece from 12, for 3 spots.
* The bar is backgammon makes you go all the way back to the beginning. This happens when the opponent lands on your piece.
* If you press enter, this skips your current turn.
* Score goes up by one when you move a piece off the board.
* Winner has a score of 15.
* The most pieces that can be in a column is 7, reject when above this.

## Test Hardness
* Run this, it will play your game from start to finish and validate your game rules. This will be used to mark the game.
* Use this during development to test as you go.
