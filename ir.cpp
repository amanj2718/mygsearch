#include "ir.h"

Record::Record(std::string str = "foo", int did = 0, int mu = 0):term(str), docid(did), freq(mu) { };

void CleanString(std::string& base_str, const std::string& filter){
}

int CountOccurrences(const std::string& base_str, const std::string& filter){
	int count = 0;
	std::size_t found = base_str.find(filter);
	while(found != std::string::npos){
		count += 1;
		// std::cout << found << std::endl;
		found = base_str.find(filter, found + 1);
	}
	return count;
}

void CreateRecords(std::string& data, int docid){
	// for each str, calculate the number of times it appears 
	// and then remove all the occurrences.
	// and create a record for the str.
}

std::string FilterStopwords(std::string& fstr){
	std::vector<std::string> stopwords = {" a ", " I ", " has ", " was ", " had ", " which ", " so ", " it "};
	for(int i = 0; i < 8; i++){
		CleanString(fstr, stopwords[i]);
		std::cout << fstr << std::endl;
	}
	return fstr;
}

void CreateIndexes(){
	// open file, assign DocID
	// CreateRecords(cleaned_str, docid);  understand how you'll receive an array of records
	// create the index
	std::ifstream fptr;
	fptr.open("example.txt", std::ios::in);
	int len = 0;
	char* buffer;
	if(fptr.is_open()){
		fptr.seekg(0, fptr.end);
		len = fptr.tellg();
		fptr.seekg(0, fptr.beg);
		buffer = new char[len];
		fptr.read(buffer, len);
		fptr.close();
	}
	std::string file_str (buffer, len);
	// std::cout << file_str << std::endl;
	// std::string cleaned_str = FilterStopwords(file_str);
	// std::cout << cleaned_str << std::endl;
	// CreateRecords(cleaned_str, 1);
}

int main(int argc, char const *argv[])
{
	// std::string s = "Aman was a boy who had a little cat which was actually so little that it was a fox.";
	// int num_a = CountOccurrences(s, " was ");
	// std::cout << num_a << std::endl;
	CreateIndexes();
	return 0;
}
