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
void TMASInformation::setPCount(int PCount){
	_thePCount = PCount;
}
int TMASInformation::getTCount(){
	return _theTCount;
}
void TMASInformation::setTCount(int TCount){
	_theTCount = TCount;
}
int TMASInformation::getECount(){
	return _theECount;
}
void TMASInformation::setECount(int ECount){
	_theECount = ECount;
}
