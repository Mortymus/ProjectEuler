#include <iostream>

bool isPrime(int value) {
	for (int i = 2; i < value - 1; i++) {
		if (value % i == 0)
			return false;
	}
	return true;
}

int main() {
	std::cout << "Project Euler 7: 10001st prime" << std::endl;

	int res;

	const int value = 10001;
	int prime_count = 0;
	int current_prime;
	int i = 2;

	while (prime_count < value) {
		if (isPrime(i)) {
			current_prime = i;
			prime_count++;
		}
		i++;
	}

	res = current_prime;

	std::cout << "Result: " << res << std::endl;
	return 0;
}

