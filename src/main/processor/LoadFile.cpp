#include <string>
#include <iostream>
#include "LoadFile.h"
#include "../model/TMASInformation.cpp"
using namespace std;

LoadFile::LoadFile(string fileName){
	_fileName = fileName;
}
string LoadFile::getFileName(){
	return _fileName;
}
TMASInformation LoadFile::load(){
	TMASInformation jobsImformation;
	
	jobsImformation.setPCount(100);
	jobsImformation.setTCount(200);
	jobsImformation.setECount(300);
	return jobsImformation;
}
