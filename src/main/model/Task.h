#include <list>
using namespace std;
class Task{
 public :
	bool isfinish();
	void setFinishTime(int);
	void setStartTime(int);
 private :
	list<int> PRED;
	int _finishTime;
	int _startTime;
};
