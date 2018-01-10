#include <iostream>
#include <list>
#include <ctime>
#include <string>
#include "processor/LoadFile.cpp"
#include "processor/GA.cpp"
using namespace std;

int main(){
	string fileName;
	int maxGeneration;
	int groupSize;
	cout << "entry file name : ";
	getline(cin,fileName);
	cout << "entry maxGeneration : ";
	cin >> maxGeneration;
	cout << "entry groupSize : ";
	cin >> groupSize;
	LoadFile loadFile(fileName);
	TMASInformation jobsInformation;
	jobsInformation = loadFile.load();
	GA ga(groupSize,maxGeneration,jobsInformation);
	double start = clock();
	cout << ga.run() << endl;;
	double end = clock();
	cout << "GA spend : "<< (end -start)/ CLOCKS_PER_SEC << " seconds"<<endl;
	system("pause");
	return 0;
}

