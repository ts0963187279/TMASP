#include <string>
#include <fstream>
using namespace std;
class TMASInformation;
class Task;
class LoadFile {
 public :
    LoadFile(string);
	string getFileName();
	TMASInformation load();
	void readBasicInformation(TMASInformation*);
	void readCommRate(TMASInformation*);
	void readCompCost(TMASInformation*);
	void readTransDataVol(TMASInformation*);
	void jumpToNextPart();
 private :
	string _fileName;
	fstream _file;
	Task* _tasks;
};
