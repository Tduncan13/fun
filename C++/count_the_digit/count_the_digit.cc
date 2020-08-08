#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int nbDig(int n, int d){
	std::vector<std::string> k;
	int count = 0;
	char D[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	for(int i = 0; i < n + 1; i++)
		k.push_back(std::to_string(i * i));

	for(int i = 0; i < k.size(); i++)
		for(char l : k[i])
			if(l == D[d]) count++;
	
	return count;
}

int main(int argc, char **argv){
	std::fstream f (argv[1]);
	std::string n;
	std::string d;

	std::getline(f, n);
	std::getline(f, d);

	std::cout << nbDig(std::stoi(n), std::stoi(d)) << std::endl;

	return 0;
}
