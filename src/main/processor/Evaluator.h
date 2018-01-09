using namespace std;
class TimeLine;
class Task;
class TMASInformation;
class Evaluator{
 public :
	Evaluator(TMASInformation);
	int getCost(int *,int *);
	bool arePREDDone(int);
	int getEarlistStartTime(int);
	TimeLine *getTimeLine();
 private :
	int _cost;
	int _thePCount;
	int _theTCount;
	Task *_tasks;
	bool *_done;
	int *_startTime;
	int *_finishTime;
	int **_transDataVol;
	double **_compCost;
	TimeLine	*_timeLine;
};
