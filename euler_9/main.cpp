#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

int main() {
	std::cout << "Project Euler 9: Special Pythagorean triplet" << std::endl;

	//Put all the digits (in their ASCII code) into a char vector
	int a, b, c;
	bool finished = false;

	for (a = 1; a < 1000; a++) {
		for (b = a + 1; b < 1000; b++) {
			c = 1000 - a - b;
			if (c < b)
				break;
			if (a*a + b*b == c*c) {
				finished = true;
				break;
			}
		}
		if (finished)
			break;
	}

	std::cout << "Result: " << std::endl;
	std::cout << "a=" << a << std::endl;
	std::cout << "b=" << b << std::endl;
	std::cout << "c=" << c << std::endl;
	std::cout << "a*b*c=" << a*b*c << std::endl;
	return 0;
}

