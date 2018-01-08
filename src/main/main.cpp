#include <iostream>
#include "processor/LoadFile.cpp"

using namespace std;

int main(){
	LoadFile loadFile("n4_00.dag");
	TMASInformation jobsInformation;
	jobsInformation = loadFile.load();
	return 0;
}
