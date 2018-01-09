#include <string>
#include "TMASInformation.h"
using namespace std;
TMASInformation::TMASInformation(){
	_thePCount = 0;
	_theTCount = 0;
	_theECount = 0;
}
int TMASInformation::getPCount(){
	return _thePCount;
}
void TMASInformation::setPCount(int pCount){
	_thePCount = pCount;
}
int TMASInformation::getTCount(){
	return _theTCount;
}
void TMASInformation::setTCount(int tCount){
	_theTCount = tCount;
}
int TMASInformation::getECount(){
	return _theECount;
}
void TMASInformation::setECount(int eCount){
	_theECount = eCount;
}
double **TMASInformation::getCommRate(){
	return _theCommRate;
}
void TMASInformation::setCommRate(double **commRate){
	_theCommRate = commRate;
}
double **TMASInformation::getCompCost(){
	return _theCompCost;
}
void TMASInformation::setCompCost(double **compCost){
	_theCompCost = compCost;
}
int **TMASInformation::getTransDataVol(){
	return _theTransDataVol;
}
void TMASInformation::setTransDataVol(int **transDataVol){
	_theTransDataVol = transDataVol;
}
void TMASInformation::setTasks(Task* tasks){
	_tasks = tasks;
}
Task* TMASInformation:: getTasks(){
	return _tasks;
}
