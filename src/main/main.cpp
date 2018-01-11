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
	cout << fileName<<endl;
	cout << "entry maxGeneration : ";
	cin >> maxGeneration;
	cout << "entry groupSize : ";
	cin >> groupSize;
	LoadFile loadFile(fileName);
	TMASInformation jobsInformation;
	jobsInformation = loadFile.load();
	GA ga(groupSize,maxGeneration,jobsInformation);
	double totalTime = 0;
	double total = 0;
	double wrost = 0;
	double best = 1e5;
	for(int i=0;i<5;i++){
		double time;
		double ans;
		double start = clock();
		ans = ga.run();
		double end = clock();
		time = (end -start)/ CLOCKS_PER_SEC;
		totalTime += time;
		total +=  ans;
		if(ans > wrost)
			wrost = ans;
		if(ans < best)
			best = ans;
		cout << ans <<endl;
		cout << time <<endl;
	}
	printf("Best:%.1f Wrost:%.1f avg:%.1f avgTime:%.3f\n",best,wrost,total/5,totalTime/5);
	return 0;
}

