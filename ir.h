#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

class Record {
	public:
		std::string term;
		int docid;
		int freq;
		Record(std::string, int, int);
};