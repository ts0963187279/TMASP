using namespace std;
class TimeLine{
 public :
	TimeLine(int);
	void setTask(int,int,int,int);
	bool hadTask(int,int,int);
 private :
	int** _processor;
}
