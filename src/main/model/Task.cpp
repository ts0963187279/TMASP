#include <list>
#include "Task.h"
using namespace std;
Task::Task(){
}
Task::setFinishTime(int finishTime){
	_finishTime = finishTime;
}
Task::setStartTime(int startTime){
	_startTime = startTime;
}
