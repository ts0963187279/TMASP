#include "GA.h"
#include "Evaluator.cpp"
#include <cstdlib>
#include <ctime>
using namespace std;
GA::GA(int groupSize, int maxGeneration, TMASInformation jobsInformation){
	_maxGeneration = maxGeneration;
	_evaluator = new Evaluator(jobsInformation);
	srand(time(NULL));
	_crossoverRate = 0.8;
	_mutationRate = 0.05;
	_groupSize = groupSize;
	int groupSizeCoefficient = 1 + _crossoverRate + _mutationRate;
	_groupFitness = new double[groupSize];
	_schedulingGroup = new int*[groupSize];
	_mappingGroup = new int*[groupSize];
	_selectionGroupSize = groupSize * (1 + _crossoverRate + _mutationRate);
	_selectionSchedulingGroup = new int *[_selectionGroupSize];
	_selectionMappingGroup = new int*[_selectionGroupSize];
	_allFitness = new double[_selectionGroupSize];
	_crossoverSize = groupSize * _crossoverRate;
	_crossoverSchedulingGroup = new int *[_crossoverSize];
	_crossoverMappingGroup = new int *[_crossoverSize];
	_mutationSize = groupSize * _mutationRate;
	_mutationSchedulingGroup = new int *[_mutationSize];
	_mutationMappingGroup = new int *[_mutationSize];
	_jobsInformation = &jobsInformation;
	_tCount = _jobsInformation->getTCount();
	_pCount = _jobsInformation->getPCount();
	_count = 0;
	_tasks = _jobsInformation->getTasks();
	_globleBestFitness = 10000.0;
	_globleBestSchedulingString = new int[_tCount];
	_globleBestMappingString = new int[_tCount];
}
double GA::run(){
	initialGroup();
	for(int i=0;i<_maxGeneration;i++){
		crossover();
		mutation();
		calculationFitness();	
		selection();
		//		cout << "Generation " << i << " Best : "<< _groupFitness[0] <<endl;
	}
	return _globleBestFitness;
}
void GA::initialGroup(){
	for(int i=0;i<_groupSize;i++){
		bool isTaskExist[_tCount] = {false};
		isTaskExist[0] = true;
		_schedulingGroup[i] = new int[_tCount];
		_mappingGroup[i] = new int[_tCount];
		_schedulingGroup[i][0] = 0;
		int pointer = 1;
		for(int j=0;j<_tCount;j++)
			_mappingGroup[i][j] = rand() % _pCount;
		for(int j=0;j<_tCount;j++){
			if(pointer == _tCount)
				break;
			list<int> SUCCList = _tasks[j].getSUCC();
			int SUCC[SUCCList.size()];
			list<int>::iterator iterator;
			int tmp = 0;
			for(iterator=SUCCList.begin();iterator!=SUCCList.end();iterator++){
				SUCC[tmp] = *iterator;
				tmp++;
			}
			double randomString[tmp];
			for(int k=0;k<tmp;k++)
				randomString[k] = (double)rand()/RAND_MAX;
			for(int k=0;k<tmp;k++){
				for(int x=0;x<tmp-k-1;x++){
					if(randomString[x] < randomString[x+1]){
						double dTmp = randomString[x];
						randomString[x] = randomString[x+1];
						randomString[x] = dTmp;
						int iTmp = SUCC[x];
						SUCC[x] = SUCC[x+1];
						SUCC[x+1] = iTmp;
					}
				}
			}
			for(int k=0;k<tmp;k++)
				put(_schedulingGroup[i],SUCC[k],isTaskExist,pointer);
		}
	}
}
void GA::calculationFitness(){
	for(int i=0;i<_selectionGroupSize;i++){
		if(i < _groupSize){
			_selectionSchedulingGroup[i] = _schedulingGroup[i];
			_selectionMappingGroup[i] = _mappingGroup[i];
		}else if(i - _groupSize < _crossoverSize){
			_selectionSchedulingGroup[i] = _crossoverSchedulingGroup[i - _groupSize];
			_selectionMappingGroup[i] = _crossoverMappingGroup[i - _groupSize];
		}else if(i - _groupSize - _crossoverSize < _mutationSize){
			_selectionSchedulingGroup[i] = _mutationSchedulingGroup[i - _groupSize - _crossoverSize];
			_selectionMappingGroup[i] = _mutationMappingGroup[i - _groupSize - _crossoverSize];
		}
	}
	for(int i=0;i<_selectionGroupSize;i++){
		_allFitness[i] = _evaluator->getCost(_selectionSchedulingGroup[i],_selectionMappingGroup[i]);
		//		cout << _allFitness[i]<< " ";
	}
}
void GA::selection(){
	double maxFitness =0;
	double *wheel = new double[_selectionGroupSize];
	double accumulation = 0;
	for(int i=0;i<_selectionGroupSize;i++){
		if(_allFitness[i] < _globleBestFitness){
			_globleBestFitness = _allFitness[i];
			_globleBestSchedulingString = _selectionSchedulingGroup[i];
			_globleBestMappingString = _selectionMappingGroup[i];
		}
	}
	for(int i=0;i<_selectionGroupSize;i++){
		maxFitness += _allFitness[i];
	}
	for(int i=0;i<_selectionGroupSize;i++){
		wheel[i] = accumulation;
		accumulation += maxFitness/_allFitness[i];
	}
	_schedulingGroup[0] = _globleBestSchedulingString;//_selectionSchedulingGroup[0];
	_mappingGroup[0] = _globleBestMappingString;//_selectionMappingGroup[0];
	_groupFitness[0] = _globleBestFitness;//_allFitness[0];
	for(int i=1;i<_groupSize;i++){
		double shot = (double)rand()/(RAND_MAX);
		shot *=  accumulation;
		for(int j=0;j<_selectionGroupSize;j++){
			if(shot < wheel[j]){
				_schedulingGroup[i] = _selectionSchedulingGroup[j-1];
				_mappingGroup[i] = _selectionMappingGroup[j-1];
				_groupFitness[i] = _allFitness[j-1];
				break;
			}
			if(j+1 == _selectionGroupSize){
				_schedulingGroup[i] = _selectionSchedulingGroup[j];
				_mappingGroup[i] = _selectionMappingGroup[j];
				_groupFitness[i] = _allFitness[j];
			}
		}
	}
}
void GA::crossover(){
	for(int i=0;i<_crossoverSize;i++){
		int randomA;
		int randomB;
		randomA = rand() % _groupSize;
		randomB = rand() % _groupSize;
		_crossoverSchedulingGroup[i] = new int [_tCount];
		_crossoverMappingGroup[i] = new int [_tCount];
		crossoverOperator(_schedulingGroup[randomA],_mappingGroup[randomA],_schedulingGroup[randomB],_mappingGroup[randomB],_crossoverSchedulingGroup[i],_crossoverMappingGroup[i]);
	}
}
void GA::mutation(){
	for(int i=0;i<_mutationSize;i++){
		_mutationSchedulingGroup[i] = new int[_tCount];
		_mutationMappingGroup[i] = new int[_tCount];
		int randomA = rand() % _groupSize;
		int randomPosition = rand() % _tCount;
		int randomProcessor = rand() % _pCount;
		for(int j=0;j<_tCount;j++){
			_mutationSchedulingGroup[i][j] = _schedulingGroup[randomA][j];
			_mutationMappingGroup[i][j] = _mappingGroup[randomA][j];
		}
		_mutationMappingGroup[i][randomPosition] = randomProcessor;
	}
}
void GA::put(int * sS,int task, bool *isTaskExist, int &pointer){
	if(!isTaskExist[task]){
		list<int> PRED = _tasks[task].getPRED();
		list<int>::iterator iterator;
		for(iterator=PRED.begin();iterator!=PRED.end();iterator++){
			if(!isTaskExist[*iterator]){
				put(sS,*iterator,isTaskExist,pointer);
			}
		}
		sS[pointer] = task;
		isTaskExist[task] = true;
		pointer ++;
	}
}
void GA::crossoverOperator(int *aSS,int *aMS,int *bSS, int *bMS,int *cSS,int *cMS){
	int sBinary[_tCount];
	int mBinary[_tCount];
	bool isTaskExist[_tCount] = {false};
	int remain = 0;
	int exist = 0;
	for(int i=0;i<_tCount;i++){
		sBinary[i] = rand() %2;
		mBinary[i] = rand() %2;
	}
	for(int i=0;i<_tCount;i++){
		if(sBinary[i] == 1){
			cSS[i] = aSS[i];
			isTaskExist[aSS[i]] = true;;
			exist++;
		}
		if(mBinary[i] == 1){
			cMS[i] = aMS[i];
		}
	}
	int emptyPosition[_tCount - exist];
	int count = 0;
	for(int i=0;i<_tCount;i++){
		if(sBinary[i] == 0){
			emptyPosition[count] = i;
			count++;
		}
		if(mBinary[i] == 1){
			cMS[i] = aMS[i];
		}else{
			cMS[i] = bMS[i];
		}
	}
	for(int i=0;remain < _tCount - exist;i++){
		if(!isTaskExist[bSS[i]]){
			cSS[emptyPosition[remain]] = bSS[i];
			remain++;
		}
	}
}
