#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::string is_sorted_and_how(std::vector<int> array){
	bool result = true;

	for(int i = 1; i < array.size(); i++)
		if(array[i - 1] > array[i]) result = false;

	if(result == true) return "yes, ascending";

	result = true;

	for(int i = array.size() - 2; i > -1; i--)
		if(array[i + 1] > array[i]) result = false;
	
	return result ? "yes, descending" : "no";
}

int main(int argc, char **argv){
	std::ifstream f (argv[1]);
	std::vector<int> input;
	std::string line;

	while(std::getline(f, line)){
		input.push_back(std::stoi(line));
	}


	f.close();
	std::cout << is_sorted_and_how(input) << std::endl;

	return 0;
}

