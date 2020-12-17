#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>

void solve(std::vector<int>& list){

	std::unordered_set<int> set;

	for(int line : list){
		
		if(set.find(2020 - line) != set.end()){
			std::cout << line * (2020 - line) << std::endl;
			return;
		}
		set.insert(line);
	}

	std::cout << "FAIL" << std::endl;
}

int main(int argc, char **argv){
	std::ifstream infile(argv[1]);
	std::string line;
	std::vector<int> list;

	while(std::getline(infile, line)){
		list.push_back(std::stoi(line));
	}

	solve(list);
}
