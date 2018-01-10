#include "TimeLine.h"
using namespace std;
#define TIMEMAX  2000
TimeLine::TimeLine(int numberOfProcessor){
	_numberOfProcessor = numberOfProcessor;
	_processor = new int*[numberOfProcessor];
	for(int i=0;i<numberOfProcessor;i++){
		_processor[i] = new int[TIMEMAX];
		for(int j=0;j<TIMEMAX;j++){
			_processor[i][j] = 0;
		}
	}
}
void TimeLine::setTask(int task,int processor,double& start,double& finish){
	while(hadTask(processor,start,finish)){
	start += 1;
	finish += 1;
	}
	for(int i = start ;i < finish ;i++){
		_processor[processor][i] = task;
	}
}
bool TimeLine::hadTask(int processor,int start,int finish){
	for(int i=start;i<finish;i++){
		if(_processor[processor][i] > 0){
			return true;
		}
	}
	return false;
}
void TimeLine::showGanttChart(int cost){
	for(int i=_numberOfProcessor-1;i>=0;i--){
		for(int j=0;j<cost;j++){
			cout << _processor[i][j] << " ";
		}
		cout << endl;
	}
}
