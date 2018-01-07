#include <string>
using namespace std;
class TMASInformation;
class LoadFile {
 public :
    LoadFile(string);
	string getFileName();
	TMASInformation load();
 private :
	string _fileName;
};
