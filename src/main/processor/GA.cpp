#include "GA.h"
#include <cstdlib>
#include <ctime>
using namespace std;
GA::GA(int groupSize, int maxGeneration, TMASInformation jobsInformation){
	_maxGeneration = maxGeneration;
	srand(time(NULL));
	_crossoverRate = 0.8;
	_mutationRate = 0.05;
	_groupSize = groupSize;
	int groupSizeCoefficient = 1 + _crossoverRate + _mutationRate;
	_schedulingGroup = new int*[groupSize];
	_mappingGroup = new int*[groupSize];
	_selectionGroupSize = groupSize * groupSizeCoefficient;
	_selectionSchedulingGroup = new int *[_selectionGroupSize];
	_selectionMappingGroup = new int*[_selectionGroupSize];
	_jobsInformation = &jobsInformation;
	_tCount = _jobsInformation->getTCount();
	crossover();
}
void GA::initialGroup(){
	for(int i=0;i<5;i++){
		
	}
	for(int i=5;i<_groupSize;i++){
		
	}
}
int GA::calculationFitness(){
	return 0;
}
void GA::selection(){
	
}
void GA::crossover(){
	int aSS[_tCount]{0,1,3,2,4,7,5,6,8,9,10};
	int aMS[_tCount]{0,1,2,3,3,2,1,0,1,1,3};
	int bSS[_tCount]{0,1,4,3,2,5,6,7,8,9,10};
	int bMS[_tCount]{0,3,2,1,1,1,1,1,2,3,1};
	crossoverOperator(aSS,aMS,bSS,bMS);
}
void GA::mutation(){
	
}
void GA::crossoverOperator(int *aSS,int *aMS,int *bSS, int *bMS){
	int sBinary[_tCount];
	int mBinary[_tCount];
	bool isTaskExist[_tCount];
	int cSS[_tCount];
	int cMS[_tCount];
	int remain = 0;
	int exist = 0;
	for(int i=0;i<_tCount;i++){
		sBinary[i] = rand() %2;
		mBinary[i] = rand() %2;
		isTaskExist[i] = false;
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
	cout << "cSS : ";
	for(int i=0;i<_tCount;i++){
		cout << cSS[i] << " ";
	}
	cout << endl;
	cout << "cMS : ";
	for(int i=0;i<_tCount;i++){
		cout << cMS[i]<<" ";
	}
	cout <<endl;
}

