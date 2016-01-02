#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

bool isPalindrome(long long value) {
	std::vector<int> digits;
	
	while (value > 0) {
		int digit = value % 10;
		digits.push_back(digit);
		value /= 10;
	}

	for (unsigned int i = 0; i < digits.size() / 2; i++) {
		if (digits.at(i) != digits.at(digits.size() - 1 - i))
			return false;
	}
	return true;
}

int main() {
	std::cout << "Project Euler 4: Largest palindrome product" << std::endl;

	int res = 0;
	
	for (int i = 100; i < 1000; i++) {
		for (int j = i; j < 1000; j++) {
			int product = i * j;
			if (isPalindrome(product)) {
				if (product > res)
					res = product;
			}
		}
	}

	std::cout << "Result: " << res << std::endl;
	return 0;
}

