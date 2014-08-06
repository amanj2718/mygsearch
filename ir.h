#include <iostream>
#include <fstream>
#include <vector>

class Record {
	public:
		std::string term;
		int docid;
		int freq;
		Record(std::string, int, int);
};