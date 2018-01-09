#include <iostream>
#include <list>
#include "processor/LoadFile.cpp"
#include "processor/Evaluator.cpp"
#include "processor/GA.cpp"
using namespace std;

int main(){
	LoadFile loadFile("test.dag");
	TMASInformation jobsInformation;
	jobsInformation = loadFile.load();
	Task * tasks = jobsInformation.getTasks();
	for(int i=0;i<jobsInformation.getTCount();i++){
		list<int> PRED = tasks[i].getPRED();
		list<int>::iterator PREDIterator;
		cout << "task : " << i << " Pred : ";
		for(PREDIterator=PRED.begin();PREDIterator!=PRED.end();PREDIterator++)
			cout << *PREDIterator << " ";
		cout <<endl;
	}
	cout << jobsInformation.getPCount()<<endl;
	cout << jobsInformation.getTCount()<<endl;
	cout << jobsInformation.getECount()<<endl;
	Evaluator evaluator(jobsInformation);
	//	int * schedulingString = new int[20];
	//	for(int i=0;i<20;i++){
	//	schedulingString[i] = i;
	//	}
	//	int * mappingString = new int[20];
	//	for(int i=0;i<20;i++){
	//		mappingString[i] = i%4;
	//	}
	int schedulingString[11]{0,1,3,2,4,7,5,6,8,9,10};
	int mappingString[11]{0,3,0,1,2,3,0,1,1,0,0};
	
	int cost =  evaluator.getCost(schedulingString,mappingString);
	TimeLine *timeLine = evaluator.getTimeLine();
	timeLine->showGanttChart(cost);
	cout << cost <<endl;
	GA ga(100,20,jobsInformation);
	return 0;
}
