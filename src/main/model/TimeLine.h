using namespace std;
class TimeNode;
class TimeLine{
 public :
	TimeLine(int);
	void setTask(int,int,double&,double&);
	void showGraph();
 private :
	TimeNode** _processor;
	int _numberOfProcessor;
};
