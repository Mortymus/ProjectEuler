#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

int main() {
	std::cout << "Project Euler 8: Largest product in a series" << std::endl;

	//Put all the digits (in their ASCII code) into a char vector
	std::ifstream input_file;
	std::string new_line;
	input_file.open("input.txt");
	std::vector<int> digits;

	while (!input_file.eof()) {
		std::getline(input_file, new_line);
		std::copy(new_line.begin(), new_line.end(), std::back_inserter(digits));
	}

	//Transform from ASCII code to actual integer value
	std::transform(digits.begin(), digits.end(), digits.begin(), std::bind1st(std::plus<int>(), -48));

	long long res = 0;

	for (unsigned int i = 0; i < digits.size() - 12; i++) {
		long long product = 1;
		for (int j = 0; j < 13; j++) {
			product *= digits[i + j];
		}
		std::cout << std::endl;
		if (product > res)
			res = product;
	}

	std::cout << "Result: " << res << std::endl;
	return 0;
}

