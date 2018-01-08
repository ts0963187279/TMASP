#include <string>
#include <iostream>
#include <fstream>
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
	TMASInformation jobsInformation;
	_file.open(_fileName,ios::in);
	jumpToNextPart();
	readBasicInformation(&jobsInformation);
	jumpToNextPart();
	readCommRate(&jobsInformation);
	jumpToNextPart();
	readCompCost(&jobsInformation);
	jumpToNextPart();
   	readTransDataVol(&jobsInformation);
	_file.close();
	return jobsInformation;
}
void LoadFile::jumpToNextPart(){
	string lineStr;
	while(lineStr.find("/*====",0)){
		getline(_file,lineStr,'\n');
	}
	while(lineStr.find("*/====",0)){
		getline(_file,lineStr,'\n');
	}
}
void LoadFile::readBasicInformation(TMASInformation* jobsInformation){
	int inputInt;
	_file >> inputInt;
 	jobsInformation->setPCount(inputInt);
	_file >> inputInt;
	jobsInformation->setTCount(inputInt);
	_file >> inputInt;
	jobsInformation->setECount(inputInt);
}
void LoadFile::readCommRate(TMASInformation* jobsInformation){
	double inputDouble;
	double **commRate;
	commRate = new double*[jobsInformation->getPCount()];
	for(int i=0;i<jobsInformation->getPCount();i++){
		commRate[i] = new double[jobsInformation->getPCount()];
		for(int j=0;j<jobsInformation->getPCount();j++){
			_file >> inputDouble;
			commRate[i][j] = inputDouble;
		}
	}
	jobsInformation->setCommRate(commRate);
}
void LoadFile::readCompCost(TMASInformation* jobsInformation){
	double inputDouble;
	double **compCost;
	compCost = new double*[jobsInformation->getTCount()];
	for(int i=0;i<jobsInformation->getTCount();i++){
		compCost[i] = new double[jobsInformation->getPCount()];
		for(int j=0;j<jobsInformation->getPCount();j++){
			_file >> inputDouble;
			compCost[i][j] = inputDouble;
		}
	}
	jobsInformation->setCompCost(compCost);
}
void LoadFile::readTransDataVol(TMASInformation* jobsInformation){
	int inputInt;
	int **transDataVol;
	int edge = 0;
	int tFrom;
	int tTo;
	int tmpTransDataVol;
	transDataVol = new int*[jobsInformation->getTCount()];
	for(int i=0;i<jobsInformation->getTCount();i++){
		transDataVol[i] = new int[jobsInformation->getTCount()];
		for(int j=0;j<jobsInformation->getTCount();j++){
			transDataVol[i][j] = 1e9;
		}
	}
	while(_file.eof() == false){
		_file >> tFrom;
		_file >> tTo;
		_file >> tmpTransDataVol;
		transDataVol[tFrom][tTo] = tmpTransDataVol;
	}
	cout << edge <<endl;
	jobsInformation->setTransDataVol(transDataVol);
}
