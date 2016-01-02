#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

bool isPrime(long long value) {
	for (int i = 2; i < value - 1; i++) {
		if (value % i == 0)
			return false;
	}
	return true;
}

int main() {
	std::cout << "Project Euler 3: Largest prime factor" << std::endl;
	long long number = 600851475143;
	std::vector<long long> factors;
	long long largest_factor = number;
	long long res;
	//Get all factors (including non-prime factors)
	for (long long i = 2; i < largest_factor - 1; i++) {
		if (number % i == 0) {
			factors.push_back(i);
			largest_factor = number / i;
			factors.push_back(largest_factor);
		}
	}

	//Sort factors in ascending order
	std::sort(factors.begin(), factors.end());

	//Iterate over factors back to front and check for prime numbers
	for (std::vector<long long>::reverse_iterator it = factors.rbegin(); it != factors.rend(); it++) {
		if (isPrime(*it)) {
			res = *it;
			break;
		}
		
	}

	std::cout << "Result: " << res << std::endl;
	return 0;
}

