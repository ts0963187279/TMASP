#include "TimeLine.h"
#include "TimeNode.cpp"
using namespace std;
#define TIMEMAX  2000
TimeLine::TimeLine(int numberOfProcessor){
	_numberOfProcessor = numberOfProcessor;
	_processor = new TimeNode*[numberOfProcessor];
	for(int i=0;i<numberOfProcessor;i++){
		_processor[i] = new TimeNode;
		_processor[i]->setStartTime(0);
		_processor[i]->setFinishTime(0);
		_processor[i]->setTaskNumber(888);
	}
}
void TimeLine::setTask(int task,int processor,double& start,double& finish){
	TimeNode *insert;
	TimeNode *now = _processor[processor];
	TimeNode *next;
	double length = finish - start;
	insert = new TimeNode;
	insert->setTaskNumber(task);
	while(true){
		if(now->getNext() == NULL){
			now->setNext(insert);
			if(now->getFinishTime() > start){
				start = now->getFinishTime();
				finish = start + length;
			}
			insert->setStartTime(start);
			insert->setFinishTime(finish);
			break;
		}
		next = now->getNext();
		if(start > now->getFinishTime() && finish < now->getStartTime()){
			now->setNext(insert);
			insert->setStartTime(start);
			insert->setFinishTime(finish);
			insert->setNext(next);
			break;
		}
		now = next;
		next = next->getNext();
		//		showGraph();
		//		cout << endl;
	}
}
void TimeLine::showGraph(){
	TimeNode *  show;
	for(int i=0;i<_numberOfProcessor;i++){
		show = _processor[i];
		cout << "processor : " << i << "   ";
		while(true){
			cout<<"|"<<show->getStartTime()<<" | "<<show->getTaskNumber()<<" | "<<show->getFinishTime()<<"|";
			cout << "-->";
			if(show->getNext() == NULL){
				cout << "break";
				break;
			}
			show = show->getNext();
		}
		cout << endl;
	}
}
