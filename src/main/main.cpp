#include <iostream>
#include "processor/LoadFile.cpp"

using namespace std;

int main(){
	LoadFile loadFile("this is file name");
	TMASInformation jobsImformation;
	jobsImformation = loadFile.load();
	cout << jobsImformation.getPCount() <<endl;
	cout << jobsImformation.getTCount() <<endl;
	cout << jobsImformation.getECount() <<endl;
	return 0;
}