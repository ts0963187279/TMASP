#include <string>

using namespace std;

class TMASInformation {
 public :
	TMASInformation();
	int getPCount();
	void setPCount(int);
	int getTCount();
	void setTCount(int);
	int getECount();
	void setECount(int);
	double getCommRate(int,int);
	void setCommRate(double **);
	double getCompCost(int,int);
	void setCompCost(double **);
	int getTransDataVol(int,int);
	void setTransDataVol(int **);
 private :
	int _thePCount;
	int _theTCount;
	int _theECount;
	double **_theCommRate;
	double **_theCompCost;
	int **_theTransDataVol;
};
