#include "Evaluator.h"
#include "../model/TimeLine.cpp"
Evaluator::Evaluator(TMASInformation jobsInformation){
	_thePCount = jobsInformation.getPCount();
	_theTCount = jobsInformation.getTCount();
	_tasks = jobsInformation.getTasks();
	_transDataVol = jobsInformation.getTransDataVol();
	_compCost = jobsInformation.getCompCost();
	_commRate = jobsInformation.getCommRate();
	_done = new bool[_theTCount];
	_startTime = new int[_theTCount];
	_finishTime = new int[_theTCount];
}
int Evaluator::getCost(int *schedulingString,int *mappingString){
	_schedulingString = schedulingString;
	_mappingString = mappingString;
	_cost = 0;
	_timeLine = new TimeLine(_thePCount);
  	for(int i=1;i<_theTCount;i++){
		_done[i] = false;
		_startTime[i] = -1;
		_finishTime[i] = -1;
	}
	_startTime[0] = 0;
	_finishTime[0] = 0;
	_done[0] = true;
	for(int i=0;i<_theTCount;i++){
		if(arePREDDone(schedulingString[i])){
			int startTime = getEarlistStartTime(schedulingString[i]);
			int finishTime = startTime + _compCost[schedulingString[i]][mappingString[schedulingString[i]]];
			_timeLine->setTask(schedulingString[i],mappingString[schedulingString[i]],startTime,finishTime);
			if(finishTime > _cost){
				_cost = finishTime;
			}
			cout <<"task : "<< schedulingString[i] <<" at processor : "<< mappingString[schedulingString[i]]<<" start : " << startTime << " finish : "<< finishTime<<endl;
			_finishTime[schedulingString[i]] = finishTime;
			_startTime[schedulingString[i]] = startTime;
			_done[schedulingString[i]] = true;
		}else{
			_cost = 1e9;
		}
	}
	return _cost + 1;
}
bool Evaluator::arePREDDone(int task){
	list<int> PRED = _tasks[task].getPRED();
	list<int>::iterator PREDIterator;
	for(PREDIterator=PRED.begin();PREDIterator!=PRED.end();PREDIterator++){
		if(!_done[*PREDIterator]){
			return false;
		}
	}
	return true;
}
int Evaluator::getEarlistStartTime(int task){
	int earliestStartTime = -1;
	list<int> PRED = _tasks[task].getPRED();
	list<int>::iterator PREDIterator;
	for(PREDIterator=PRED.begin();PREDIterator!=PRED.end();PREDIterator++){
		int isSameProcessor = 1;
		if(_mappingString[task] == _mappingString[*PREDIterator]){
			isSameProcessor = 0;
		}
		if(_finishTime[*PREDIterator] + _transDataVol[*PREDIterator][task] * isSameProcessor > earliestStartTime)
			earliestStartTime = _finishTime[*PREDIterator] + _transDataVol[*PREDIterator][task] * isSameProcessor;
	}
	return earliestStartTime;
}
TimeLine *Evaluator::getTimeLine(){
	return _timeLine;
}
