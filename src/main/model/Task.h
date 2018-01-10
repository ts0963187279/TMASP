#include <list>
using namespace std;
class Task{
 public :
	Task();
	bool isFinish();
	void setStartTime(int);
	int getStartTime();
	void setFinishTime(int);
	int getFinishTime();
	void addPRED(int);
	void addSUCC(int);
	void setEarliestStartTime(int);
	list<int> getPRED();
	list<int> getSUCC();
 private :
	list<int> _PRED;
	list<int> _SUCC;
	int _earliestStartTime;
	int _startTime;
	int _finishTime;
};
