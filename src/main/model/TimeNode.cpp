#include "TimeNode.h"
using namespace std;
void TimeNode::setNext(TimeNode * next){
	_next = next;
}
TimeNode * TimeNode::getNext(){
	return _next;
}
void TimeNode::setStartTime(double startTime){
	_startTime = startTime;
}
double TimeNode::getStartTime(){
	return _startTime;
}
void TimeNode::setFinishTime(double finishTime){
	_finishTime = finishTime;
}
double TimeNode::getFinishTime(){
	return _finishTime;
}
void TimeNode::setTaskNumber(int taskNumber){
	_taskNumber = taskNumber;
}
int TimeNode::getTaskNumber(){
	return _taskNumber;
}
