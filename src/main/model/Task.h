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
	void setEarliestStartTime(int);
	list<int> getPRED();
 private :
	list<int> _PRED;
	int _earliestStartTime;
	int _startTime;
	int _finishTime;
};
