#include <iostream>

int main() {
	std::cout << "Project Euler 6: Sum square difference" << std::endl;

	int res;

	const int value = 100;

	int sum = value * (value + 1) / 2;
	int squared_sum = sum * sum;
	int sum_squares = 0;

	for (int i = 1; i <= 100; i++) {
		sum_squares += i * i;
	}

	res = squared_sum - sum_squares;

	std::cout << "Result: " << res << std::endl;
	return 0;
}

