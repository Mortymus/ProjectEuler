#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

bool isPrime(int value) {
	for (int i = 2; i < value - 1; i++) {
		if (value % i == 0)
			return false;
	}
	return true;
}

int main() {
	std::cout << "Project Euler 10: Summation of primes" << std::endl;

	long long res = 0;
	int limit = 2000000;
	std::vector<int> primes(limit);
	primes.push_back(2);
	primes.push_back(3);
	std::vector<int> all_numbers;
	for (int i = 4; i < limit; i++) {
		if(i%2 != 0)
			all_numbers.push_back(i);
	}

	bool removed_number = true;
	while (removed_number) {
		removed_number = false;
		int current_prime = primes.back();
		bool found_next_prime = false;
		int zero_count = 0;
		std::cout << "Processing prime: " << current_prime << std::endl;

		for (auto it = all_numbers.begin(); it != all_numbers.end();) {
			if (*it != 0 && *it % current_prime == 0) {
				*it = 0;
				zero_count++;
				removed_number = true;
			}
			else {
				if (!found_next_prime && *it != 0) {
					found_next_prime = true;
					primes.push_back(*it);
				}
				it++;
			}
		}
		if (zero_count >= 100000) {
			std::vector<int> stripped;
			std::copy_if(all_numbers.begin(), all_numbers.end(), std::back_inserter(stripped), [](const int a) { return a != 0; });
			all_numbers = stripped;
			zero_count = 0;
		}
	}

	for (auto value : primes) {
		res += value;
	}

	std::cout << "Result: " << res << std::endl;
	return 0;
}

