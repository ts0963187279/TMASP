#include <list>
#include "Task.h"
using namespace std;
Task::Task(){
	_earliestStartTime = -1;
	_finishTime = -1;
}
bool Task::isFinish(){
	if(_finishTime > -1)
		return true;
	return false;
}
void Task::setStartTime(int startTime){
	_startTime = startTime;
}
int Task::getStartTime(){
	return _startTime;
}
void Task::setFinishTime(int finishTime){
	_finishTime = finishTime;
}
int Task::getFinishTime(){
	return _finishTime;
}
void Task::setPRED(list<int> PRED){
	_PRED = PRED;
}
void Task::setEarliestStartTime(int earliestStartTime){
	if(earliestStartTime > _earliestStartTime){
		_earliestStartTime = earliestStartTime;
	}
}
list<int> Task::getPRED(){
	return _PRED;
}

