#include <iostream>
#include <limits>

int main() {
	std::cout << "Project Euler 5: Smallest multiple" << std::endl;

	int res;

	for (int i = 20; i < std::numeric_limits<int>::max(); i += 20) {
		//Start at 3 as multiples of 20 are already divisible by 1 and 2
		int j = 3;
		for (; j < 20; j++) {
			if (i % j != 0)
				break;
		}
		if (j == 20) {
			res = i;
			break;
		}
	}

	std::cout << "Result: " << res << std::endl;
	return 0;
}

