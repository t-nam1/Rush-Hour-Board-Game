## COMP2113_ENGG1340 Programming technologies and Computer programming II

### Team Details: 
**Team Number** (on Moodle): 21

**Members**:
* Jose Joaquin Marquez (3036263622)
* Taeuk Nam (3035709332)
* Kazi Ishmam Hamid (3036184010)
* Julia Handiprima (3036262094)
* Lua Xuan Zi (3036181680)

### Game Description and Rules: 

*Hungry Hour* is a strategic puzzle game based on the traditional mechanics of the Rush Hour board game, but with a delightful twist. In this game, players must help the smiley face 😀, known as James, navigate through a gridlocked board to reach the far right exit. The board is cluttered with various cars, each represented by colorful blocks that can only move horizontally/vertically in line with their orientation. 

Your task is to devise a path for James by using simple commands to move coloured cars left-right or up-down, and move James to its destination - the far right exit. Cars come in multiple colors including Red 🟥, Orange 🟧, Purple 🟪, and others, each designated by a unique letter for easy command input. You cannot go through cars if they are in the way. Remember, James can only move horizontally. 

Examples of commands: 
* 'j r 4': move **James**, **4** blocks to the **right**.
* 'o u 2': move **Orange car**, **2** blocks **up**.
* 'r d 1': move **Red car**, **1** blocks **down**.
* 'w l 3': move **White car**, **3** blocks **left**.

Earn more points by winning each round quicker! Points depend on how quick you solve the round and how many moves you use, the max being 1000 points. You can exit the game at any moment by pressing 'q'. Plan your moves carefully and lead James to victory in this engaging puzzle challenge!

### List of features implemented 

* Generation of random game sets or events - each game randomly generates each map, with each round getting more difficult for players
* Data structures for storing game status (e.g., arrays, STL containers) - inserts user name to store in leaderboard
* Dynamic memory management (e.g., dynamic arrays, linked lists, STL containers)
* File input/output (e.g., for loading/saving game status) - inserts user name to store in leaderboard
* Program codes in multiple files (recall separate compilation)
* Proper indentation and naming styles
* In-code documentation

### List of non-standard C/C++ libraries
* string - for string manipulation
* sstream - for stream operations
* vector - for dynamic arrays
* tuple - for the tuple class
* cstdlib - dynamic memory management and random number generation
* ctime - for time calculation
* cassert - diagnostic testing
* chrono - stopwatch feature
* cmath - for time calculations
* algorithm - for sorting and searching
* limits - query properties of fundamental data types
* thread - for the thread class

### Compilation and execution instructions 

Type these line by line:

1) make Car.o
2) make GameLogic.o
3) make GameUtilities.o
4) make Leaderboard.o
5) make Main.o
6) make main
7) ./main

-----

_About the game:_

## HUNGRY HOUR - Escape the Parking Lot!

In the heart of the bustling city, James, a university student embarks on a journey to fulfill his hunger, only to find himself facing a whirlwind day filled with errands and escapades, as he gets entangled in a web of obstacles that put his patience and strategic prowess to the test. From escaping his jam-packed apartment parking lot to navigating a gas station gridlock, battling through campus chaos, while racing against his growling stomach, James' journey is a thrilling and hunger-filled urban odyssey. With your help, he will conquer each challenge, clear the path to success, and ultimately satisfy his hunger. Join James in his quest to triumph over the city's chaos, and together, let's embark on a thrilling rush hour adventure on the search for food, filled with laughter, excitement, and delicious discoveries. Get ready to drive, strategize, and savor every moment!

### GAME SCENARIO

##### Prologue
Meet James, a lively university student with a penchant for punctuality and a serious love for good food. As James prepares for a bustling day filled with errands and engagements, he encounters a series of challenging obstacles that will test his patience and strategic prowess.

##### Chapter 1: Escape from the Apartment (Maps 1 & 2)
Our story begins in the cozy confines of James's apartment. Eager to satiate his growing hunger with a hearty dinner, James heads to his car, only to find the apartment's parking lot jam-packed with haphazardly parked cars. Your mission: swiftly clear a path for James's car. Remember, James's hunger grows by the minute—time is of the essence!

##### Chapter 2: The Gas Station Gridlock (Maps 3 & 4)
Victory at the apartment! But just as James hits the road, his fuel gauge hits empty. Next stop: the nearest gas station. Unfortunately, it's rush hour, and the station is overwhelmed with vehicles. Help James maneuver through the clutter of trucks and cars to reach the pump before his car runs dry.

##### Chapter 3: Racing Against Hunger (Maps 5 & 6)
With the tank full, James's attention returns to his stomach. However, delays have taken toll, and his hunger is now critical. Navigate  James swiftly to the nearest eatery. Beware: if he doesn't eat soon, his energy will plummet, adding urgency to your challenge.

##### Chapter 4: Academic Urgency (Maps 7 & 8)
Refueled and refed, James remembers a pressing deadline: he must deliver a document to his lecturer at Hong Kong University. The campus roads are choked with vehicles. Clear a path for James so he can hand in his assignment on time and avoid academic disaster.

##### Chapter 5: Campus Chaos (Maps 9 & 10)
Document submitted, James now needs to exit the labyrinthine university campus. Unfortunately, the end-of-day traffic has left the campus roads congested with parked cars. It's up to you to find a route that will get James out without delay.

##### Chapter 6: Festive Frenzy at the Mall (Maps 11 & 12)
Finally, it's time for  Fook to unwind. He heads to the shopping mall to meet friends for a festive dinner during the Chinese New Year celebrations. But the mall parking lot is an absolute maze of vehicles. Help  Fook navigate through the festive chaos to find a spot where he can park and relax.

##### Epilogue: The Final Park (Maps 13 & 14)
James's nearly there, but there's one last challenge. Inside the crowded mall parking lot, you must strategically shift cars to secure a parking space for  Fook. Success means a well-deserved evening of fun and relaxation.

##### Closing
Join James in this urban adventure, solving puzzles and battling the clock to navigate the complexities of city life. Each map offers a unique challenge that not only tests your problem-solving skills but also brings Fook closer to his goals. Ready, set, drive!

