# README

# Description
This project contains a program which are logically correct, but it lacks a makefile and has some missing headers and global variables across a few files. We have to understand that and add reuired headers and global variables.

# Header files to add inside the main.cpp
    #include <algorithm>
    #include <vector>
    #include "LibraryItem.cpp"
    #include "User.cpp"
    #include "Library.cpp"
    #include "classFunctions.cpp"
    #include "functions.cpp"  

# Header files to add inside the User.cpp
    #include "Journals.cpp"
    #include "PublicationRank.cpp"
    #include "Book.cpp"

```bash
test:
# main
	g++ -c main.cpp
	g++ -g -o debug1 main.o
	g++ -O3 -o optimize1 main.o
