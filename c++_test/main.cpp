#include <iostream>

int main() {
	std::cout << "Project Euler 1: Multiples of 3 and 5" << std::endl;
	int res = 0;
	for (int i = 0; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0)
			res += i;
	}
	std::cout << "Result: " << res << std::endl;
	return 0;
}