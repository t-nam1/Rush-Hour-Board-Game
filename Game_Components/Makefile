FLAGS = -pedantic-errors -std=c++11

Car.o: Car.cpp Car.h
	g++ $(FLAGS) -c Car.cpp

GameLogic.o: GameLogic.cpp GameLogic.h
	g++ $(FLAGS) -c GameLogic.cpp

GameUtilities.o: GameUtilities.cpp GameUtilities.h
	g++ $(FLAGS) -c GameUtilities.cpp

Leaderboard.o: Leaderboard.cpp Leaderboard.h
	g++ $(FLAGS) -c Leaderboard.cpp

Main.o: Main.cpp
	 g++ $(FLAGS) -c Main.cpp

main: Car.o GameLogic.o GameUtilities.o Leaderboard.o Main.o
	g++ $(FLAGS) Car.o GameLogic.o GameUtilities.o Leaderboard.o Main.o -o main

test: main
	./main

clean:
	rm -f main Car.o GameLogic.o GameUtilities.o Leaderboard.o Main.o

.PHONY: clean test
