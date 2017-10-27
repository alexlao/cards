To whomever this concerns, thank you for your time and consideration.
This document explains how to compile/run the program and my thought process.

================================
SET-UP
================================
The project includes a Makefile for you to use at your convenience.
Running the 'make' command will create an executable called calculateRounds. Run this program with any integer greater than 0.
The progarm is compiled using GCC and a few flags.

================================
THOUGHT PROCESS
================================
Initially, I was hoping to create and solve a recurrence relation for this problem.
As I began to run through several rounds of different deck sizes, I realized that this would not be feasible. 
While computing rounds of larger decks, I discovered a pattern: there were sets of cards in the deck that would rotate spots.
The rotational period of each set is the number of cards in that set. 
After the rotational period, each card in the set should return to its initial spot.
Therefore, ALL cards should be back in its initial spot at a round where every set has completed its rotational period.
In essence, the least common multiple of the set sizes in the deck is the number of rounds it will take to return to its original state.

My solution to solve the amount of rounds is as follows:
	- Generate a deck of cards with the specified size.
	- Complete one round of moving the cards.
	- Iterate through the array to determine how big each rotational set is.
	- Find the least common multiple of the size of the sets.

I decided to represent the deck through a linked list for multiple reasons:
	- The ability to add a card to the end of the deck at constant speed.
	- The ability to draw the card at the top of the deck at constant speed.
	- The ability to iterate through the deck until there are no cards lefts.

After the single round of play is completed, I decided to store the data in an array.
An array allows access to any index at constant speed, which is important, as I have to follow the cards to determine the sets.

================================
TOOLS USED
================================
To develop this program, I used several tools:
	- Vim -> Text Editor
	- Valgrind -> Memory Debugging
	- GDB -> Debugger
	- GitHub -> Version Control
================================

Once again, thank you for your time and consideration.
If you have any questions about my program, please feel free to contact me at lao.alex97@gmail.com or (847)-624-9797.


               --         
            /dm/         
        `  .hs-`         
     :ymmmdsydmmmh+      
    +mmmmmmmmmmmmy`      
    dmmmmmmmmmmmm`       
    hmmmmmmmmmmmm+       
    :mmmmmmmmmmmmmh-     
     /mmmmmmmmmmmmy`     
      -ymmdyyhmmd/       
        ``     `       