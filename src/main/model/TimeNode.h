using namespace std;
class TimeNode{
 public :
	void setNext(TimeNode *);
	TimeNode * getNext();
	void setStartTime(double);
	double getStartTime();
	void setFinishTime(double);
	double getFinishTime();
	void setTaskNumber(int);
	int getTaskNumber();
 private :
	double _startTime;
	double _finishTime;
	TimeNode * _next;
	int _taskNumber;
};
