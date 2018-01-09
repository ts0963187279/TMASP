using namespace std;
class TMASInformation;
class GA {
 public:
	GA(int,int,TMASInformation);
	int calculationFitness();
	void run();
	void initialGroup();
	void selection();
	void crossover();
	void mutation();
 private:
	
	double _mutationRate;
	double _crossoverRate;
	int ** _group;
	int _groupSize;
	int _maxGeneration;
	TMASInformation *_jobsInformation;
	int _tCount;
};
