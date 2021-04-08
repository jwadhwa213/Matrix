#--------------------------------------------
#   Name: Jasmine Kaur Wadhwa
#   ID: 1619400
#   CMPUT 275, Winter 2021
#
#   Weekly Exercise #4 Makefile
#--------------------------------------------

run: execute
	./execute
#cleans the file matrix.o
clean:
	rm -f matrix.o

execute: main.o matrix.o
	g++ -o execute main.o matrix.o

#compiles the file matrix.cpp
matrix.o:matrix.cpp
	g++ -c matrix.cpp

main.o:main.cpp
	g++ -c main.cpp










