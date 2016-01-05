#include <iostream>

long long getNumFactors(long long value) {
	long long res = 2;
	long long limit = value / 2;
	for (long long i = 2; i < limit ; i++) {
		if (value % i == 0) {
			limit = value / i;
			res += 2;
		}
	}
	return res;
}

int main() {
	std::cout << "Project Euler 12: Highly divisible triangular number" << std::endl;
	long long res = 0;
	long long num_divisors = 0;
	long long i = 1;
	long long little_gauss;

	while (num_divisors <= 500) {
		i++;
		little_gauss = i*(i + 1) / 2;
		num_divisors = getNumFactors(little_gauss);
	}

	res = little_gauss;
	std::cout << "Result: " << res << std::endl;
	return 0;
}

