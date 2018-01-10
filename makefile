test: main.o
	g++ -o test main.o
	rm *.o
main.o: src/main/main.cpp	
	g++ -c src/main/main.cpp
