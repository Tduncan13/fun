#include <string>
#include <vector>
#include <iostream>
#include <fstream>

void solution(const std::string &s){
	bool odd = s.length() % 2 != 0;
	int i;
	std::vector<std::string> res;

	for(i = 0; i < s.length(); i += 2)
		res.push_back(s.substr(i, 2));

	if(odd) res[res.size() - 1] = res[res.size() - 1] + '_';

	for (auto s : res) 
		std::cout << s << std::endl;
}

int main(int argc, char **argv){
	std::ifstream f (argv[1]);
	std::string line;
	
	std::getline(f, line);
	solution(line);
	f.close();
}
