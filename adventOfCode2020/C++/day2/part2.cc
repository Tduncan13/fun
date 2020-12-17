
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

	if(pw->pw[pw->range.at(0) - 1] == pw->c[0] ^ pw->pw[pw->range.at(1) - 1] == pw->c[0])
		return true;

	return false;
}

Password *createPassword(std::string s){

	Password *pw = new Password();

	std::stringstream ss(s);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	std::copy(vstrings.begin(), vstrings.end(), vstrings.begin());

	size_t pos = 0;
	std::string r = vstrings.at(0);
	std::string delimeter = "-";
	
	while((pos = vstrings.at(0).find(delimeter)) != std::string::npos){
		pw->range.push_back(std::stoi(vstrings.at(0).substr(0, pos)));
		vstrings.at(0).erase(0, pos + delimeter.length());
	}

	pw->range.push_back(std::stoi(vstrings.at(0)));
		
	delimeter = ":";
	while((pos = vstrings.at(1).find(delimeter)) != std::string::npos){
		pw->c = vstrings.at(1).substr(0, pos);
		vstrings.at(1).erase(0, pos + delimeter.length());
	}

	pw->pw = vstrings.at(2);

	return pw;
}

int main(int argc, char **argv){
	std::ifstream infile(argv[1]);
	std::string line;
	int count = 0;

	while(std::getline(infile, line)){
		Password *pw = createPassword(line);
		if(isValid(pw)) count++;
		delete pw;
	}

	std::cout << count << std::endl;
}
