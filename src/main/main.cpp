#include <iostream>
#include "processor/LoadFile.cpp"
#include "processor/Evaluator.cpp"
using namespace std;

int main(){
	LoadFile loadFile("n4_00.dag");
	TMASInformation jobsInformation;
	jobsInformation = loadFile.load();
	Evaluator evaluator;
	return 0;
}
