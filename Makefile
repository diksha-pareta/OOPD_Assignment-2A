test:
# main
	g++ -c main.cpp
	g++ -g -o debug1 main.o
	g++ -O3 -o optimize1 main.o