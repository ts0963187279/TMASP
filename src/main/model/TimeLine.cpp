#include "TimeLine.h"
using namespace std;
#define TIMEMAX  9999;
TimeLine::TimeLine(int numberOfProcessor){
	_processor = new int*[numberOfProcessor];
	for(int i=0;i<numberOfProcessor;i++){
		_processor[i] = new int[TIMEMAX];
		for(int j=0;j<TIMEMAX;i++){
			_processor[i][j] = 0;
		}
	}
}
void TimeLine::setTask(int task,int processor,int start,int finish){
	for(int i = start ;i <= finish ;i++){
		_processor[processor][i] = task;
	}
}
bool TimeLine::hadTask(int processor,int start,int finish){
	for(int i=start;i<=finish;i++){
		if(_processor[processor][i] > 0){
			return true;
		}
	}
	return false;
}
