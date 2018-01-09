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
	int * schedulingString = new int[12];
	schedulingString[0] = 0;
	schedulingString[1] = 1;
	schedulingString[2] = 3;
	schedulingString[3] = 2;
	schedulingString[4] = 4;
	schedulingString[5] = 7;
	schedulingString[6] = 5;
	schedulingString[7] = 6;
	schedulingString[8] = 8;
	schedulingString[9] = 9;
	schedulingString[10] = 10;
	int * mappingString = new int[12];
	mappingString[0] = 0;
	mappingString[1] = 3;
	mappingString[2] = 0;
	mappingString[3] = 1;
	mappingString[4] = 2;
	mappingString[5] = 3;
	mappingString[6] = 0;
	mappingString[7] = 1;
	mappingString[8] = 1;
	mappingString[9] = 0;
	mappingString[10] = 0;
	int cost =  evaluator.getCost(schedulingString,mappingString);
	TimeLine *timeLine = evaluator.getTimeLine();
	timeLine->showGanttChart(cost);
	GA ga(100,500,jobsInformation);
	return 0;
}
