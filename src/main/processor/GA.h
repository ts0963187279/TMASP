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
	void crossoverOperator(int *,int *,int *,int *);
 private:
	double _mutationRate;
	double _crossoverRate;
	int ** _schedulingGroup;
	int ** _mappingGroup;
	int ** _selectionSchedulingGroup;
	int ** _selectionMappingGroup;
	int * _crossoverSchedulingString;
	int * _crossoverMappingString;
	int _selectionGroupSize;;
	int _maxGeneration;
	int _groupSize;
	TMASInformation *_jobsInformation;
	int _tCount;
};
