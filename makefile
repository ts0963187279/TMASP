test: main.o
	g++ -o test main.o
	del *.o
main.o: src/main/main.cpp	
	g++ -c src/main/main.cpp
