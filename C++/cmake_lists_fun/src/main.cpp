#include <iostream>
#include "Vector2.h"

int main(){
	std::cout << "Hello World!" << std::endl;

	Vector2 position(2.0, 3.0);
	Vector2 speed(3.0, 4.0);

	std::cout << position.x << ", " << position.y << std::endl;

	position = position + speed;

	std::cout << position.x << ", " << position.y << std::endl;
}
