#include <string>

using namespace std;
class Task;
class TMASInformation {
 public :
	TMASInformation();
	int getPCount();
	void setPCount(int);
	int getTCount();
	void setTCount(int);
	int getECount();
	void setECount(int);
	double **getCommRate();
	void setCommRate(double **);
	double **getCompCost();
	void setCompCost(double **);
	int **getTransDataVol();
	void setTransDataVol(int **);
	Task* getTasks();
	void setTasks(Task*);
 private :
	int _thePCount;
	int _theTCount;
	int _theECount;
	double **_theCommRate;
	double **_theCompCost;
	int **_theTransDataVol;
	Task* _tasks;
};

