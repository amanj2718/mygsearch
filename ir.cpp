#include "ir.h"

Record::Record(std::string str = "foo", int did = 0, int mu = 0):term(str), docid(did), freq(mu) { };

void CleanString(std::string& base_str, const std::string& filter){
	std::size_t base_len = base_str.length();
	std::size_t filter_len = filter.length() - 1;
	std::size_t found = base_str.find(filter);
	// std::cout << "Before -- " << base_str << std::endl;
	while(found != std::string::npos){
		base_str.erase(found, filter_len);
		if(found + filter_len < base_len){
			found = base_str.find(filter, found+filter_len);
		}
		else{
			break;
		}
	}
	// std::cout << "After -- " << base_str << std::endl;
}

int CountOccurrences(const std::string& base_str, const std::string& filter){
	int count = 0;
	std::size_t base_len = base_str.length();
	std::size_t found = base_str.find(filter);
	while(found != std::string::npos){
		count += 1;
		if(found + 1 < base_len){
			found = base_str.find(filter, found + 1);
		}
		else{
			break;
		}
	}
	return count;
}

void SplitString(const std::string& data, std::vector<std::string>& split){
	// Takes a string, and splits it based on the space delimiter.
	std::size_t found = data.find(" ");
	split.push_back(data.substr(0, found));
	// std::cout << data.substr(0, found) << std::endl;
	std::size_t start = found + 1;
	while(found != std::string::npos){
		found = data.find(" ", start);
		split.push_back(data.substr(start, found - start));
		// std::cout << data.substr(start, found - start) << std::endl;
		start = found + 1;
	}
}

void CreateRecords(std::string& data, int docid, std::vector<Record*>& records){
	// for each str, calculate the number of times it appears 
	// and create a record for the str.
	std::vector<std::string> words;
	SplitString(data, words);
	for(std::vector<std::string>::iterator i = words.begin(); i != words.end(); i++){
		records.push_back(new Record(*i, docid, CountOccurrences(data, *i)));
	}
}

std::string FilterStopwords(std::string& fstr){
	// this only works with -std=c++11, change to char**.
	std::vector<std::string> stopwords = {" a ", " I ", " has ", " was ", " had ", " which ", " so ", " it ", " who ", "who ", " that "};
	for(std::vector<std::string>::iterator i = stopwords.begin(); i != stopwords.end(); i++){
		CleanString(fstr, *i);
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
	std::string cleaned_str = FilterStopwords(file_str);
	// std::cout << "No stopwords -- " << cleaned_str << std::endl;
	std::vector<Record*> records;
	CreateRecords(cleaned_str, 1, records);
}

int main(int argc, char const *argv[])
{
	// std::string s = "Aman was a boy who had a little cat which was actually so little that it was a fox.";
	// int num_a = CountOccurrences(s, " was ");
	// std::cout << num_a << std::endl;
	CreateIndexes();
	return 0;
}
