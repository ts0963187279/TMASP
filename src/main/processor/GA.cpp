#include "GA.h"
using namespace std;
GA::GA(int groupSize, int maxGeneration, TMASInformation jobsInformation){
	_maxGeneration = maxGeneration;
	_crossoverRate = 0.8;
	_mutationRate = 0.05;
	int groupSizeCoefficient = 1 + _crossoverRate + _mutationRate;
	_groupSize = groupSize * groupSizeCoefficient;
	_group = new int *[_groupSize];
	_jobsInformation = &jobsInformation;
	_tCount = _jobsInformation->getTCount();
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
	
}
void GA::mutation(){
	
}

