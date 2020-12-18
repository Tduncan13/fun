#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

bool isValid(std::unordered_map<std::string, std::string> *p){
	
	int count = 0;

	count += p->find("byr")	!= p->end() ? 1 : 0;
	count += p->find("iyr")	!= p->end() ? 1 : 0;
	count += p->find("eyr")	!= p->end() ? 1 : 0;
	count += p->find("hgt")	!= p->end() ? 1 : 0;
	count += p->find("hcl")	!= p->end() ? 1 : 0;
	count += p->find("ecl")	!= p->end() ? 1 : 0;
	count += p->find("pid")	!= p->end() ? 1 : 0;
	
	return (count == 7) ? true : false;
}

std::unordered_map<std::string, std::string> *createPassport(std::vector<std::string> record){
	std::unordered_map<std::string, std::string> *p = new std::unordered_map<std::string, std::string>();
	std::string s;

	// Break passenger info into vector
	for(std::string line : record){
		s += line + " ";
	}
	std::stringstream ss(s);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	std::copy(vstrings.begin(), vstrings.end(), vstrings.begin());

	// Break Vector into key value pairs
	size_t pos = 0;
	std::string delimeter = ":";

	for(std::string kv : vstrings){
		while((pos = kv.find(delimeter)) != std::string::npos){
			std::string key = kv.substr(0, pos);
			kv.erase(0, pos + delimeter.length());
			std::string value = kv;
			p->insert({key, value});
		}
	}

	return p;
}

int main(int argc, char **argv){
	std::ifstream infile(argv[1]);
	std::string line;
	std::vector<std::string> record;
	std::unordered_map<std::string, std::string> *passport;
	int count = 0;

	while(std::getline(infile, line)){
		
		if(line == ""){
			passport = createPassport(record);
			count += isValid(passport) ? 1 : 0;
			record.clear();
			continue;
		}
		record.push_back(line);
	}

	passport = createPassport(record);
	count += isValid(passport) ? 1 : 0;

	std::cout << count << std::endl;
}
