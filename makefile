test: main.o
	g++ -o test main.o
main.o: main.cpp
	g++ -c main.cpp
clean:
	del *.o
