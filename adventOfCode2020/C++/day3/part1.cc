
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

void countTrees(std::vector<std::string> lines){
	int count = 0;
	Vector2 move = Vector2(3, 1, lines[0].length());
	Vector2 pos = Vector2(0, 0, lines[0].length());

	while(pos.y <= lines.size()){
		if(lines[pos.y][pos.x] == '#') count++;

		pos = pos + move;
	}

	std::cout << count << std::endl;
}

int main(int argc, char **argv){
	std::ifstream infile(argv[1]);
	std::vector<std::string> lines;
	std::string line;

	while(std::getline(infile, line)){
		lines.push_back(line);
	}

	countTrees(lines);

}
