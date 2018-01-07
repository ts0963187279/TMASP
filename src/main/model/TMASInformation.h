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
 private :
	int _thePCount;
	int _theTCount;
	int _theECount;
};
