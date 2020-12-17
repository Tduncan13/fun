#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

struct Password{
	std::vector<int> range;
	std::string c;
	std::string pw;
};

bool isValid(Password *pw){
	int count = 0;
	for(char c : pw->pw){
		if(c == pw->c[0]){
			count++;	
		}
	}

	if(count < pw->range.at(0) || count > pw->range.at(1))
		return false;

	return true;
}

Password *createPassword(std::string s){

	Password *pw = new Password();

	// Split string by spaces
	std::stringstream ss(s);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	std::copy(vstrings.begin(), vstrings.end(), vstrings.begin());

	// Split string on dash
	size_t pos = 0;
	std::string r = vstrings.at(0);
	std::string delimeter = "-";
	
	while((pos = vstrings.at(0).find(delimeter)) != std::string::npos){
		pw->range.push_back(std::stoi(vstrings.at(0).substr(0, pos)));
		vstrings.at(0).erase(0, pos + delimeter.length());
	}

	pw->range.push_back(std::stoi(vstrings.at(0)));
		
	// Remove colon
	delimeter = ":";
	while((pos = vstrings.at(1).find(delimeter)) != std::string::npos){
		pw->c = vstrings.at(1).substr(0, pos);
		vstrings.at(1).erase(0, pos + delimeter.length());
	}

	// Create Password
	pw->pw = vstrings.at(2);

	return pw;
}

int main(int argc, char **argv){
	std::ifstream infile(argv[1]);
	std::string line;
	int count = 0;

	// sample line: 
	// 	1-3 a: abcde
	//
	// step 1: split on space
	// - 1-3
	// - a:
	// - abcde
	//
	//
	// step 2: split on "-"
	//
	// step 3: remove ":"
	//
	// step 4: check if password is valid

	while(std::getline(infile, line)){
		Password *pw = createPassword(line);
		if(isValid(pw)) count++;
		delete pw;
	}

	std::cout << count << std::endl;
}
