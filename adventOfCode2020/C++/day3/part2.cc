
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Vector2{
	int x, y, mod;

public: 
	Vector2(int _x, int _y, int _mod){
		x = _x;
		y = _y;
		mod = _mod;
	}

	Vector2 operator+(const Vector2& other) const {
		return Vector2((x + other.x) % mod, y + other.y, mod);
	}
};

long long countTrees(std::vector<std::string> lines, int x, int y){
	long long count = 0;
	Vector2 move = Vector2(x, y, lines[0].length());
	Vector2 pos = Vector2(0, 0, lines[0].length());

	while(pos.y <= lines.size()){
		if(lines[pos.y][pos.x] == '#') count++;

		pos = pos + move;
	}
	return count;
}

int main(int argc, char **argv){
	std::ifstream infile(argv[1]);
	std::vector<std::string> lines;
	std::string line;
	long long count = 1;

	while(std::getline(infile, line)){
		lines.push_back(line);
	}

	count *= countTrees(lines, 1, 1);
	count *= countTrees(lines, 3, 1);
	count *= countTrees(lines, 5, 1);
	count *= countTrees(lines, 7, 1);
	count *= countTrees(lines, 1, 2);
	
	std::cout << count << std::endl;

}
