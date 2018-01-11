using namespace std;
class TimeLine;
class Task;
class TMASInformation;
class Evaluator{
 public :
	Evaluator(TMASInformation);
	double getCost(int *,int *);
	bool arePREDDone(int);
	int getEarlistStartTime(int);
	TimeLine *getTimeLine();
 private :
	double _cost;
	int _thePCount;
	int _theTCount;
	Task *_tasks;
	bool *_done;
	double *_startTime;
	double *_finishTime;
	int **_transDataVol;
	double **_commRate;
	double **_compCost;
	TimeLine *_timeLine;
	int *_schedulingString;
	int *_mappingString;
};
