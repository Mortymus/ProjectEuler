#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> getFactors(long long value, bool include_one = true, bool include_value = true) {
	std::vector<long long> res;
	if (include_value)
		res.push_back(value);
	if (include_one && value != 1)
		res.push_back(1);
	long long limit = value;
	for (long long i = 2; i < limit; i++) {
		if (value % i == 0) {
			limit = value / i;
			res.push_back(i);
			if(limit != i)
				res.push_back(limit);
		}
	}

	return res;
}

int main() {
	std::cout << "Project Euler 21: Amicable numbers" << std::endl;
	long long res = 0;
	std::vector<int> amicable_numbers;

	for (int i = 2; i < 10000; i++) {
		auto factors = getFactors(i, true, false);

		int factors_sum = 0;
		for (auto factor : factors) {
			factors_sum += factor;
		}

		auto sum_factors = getFactors(factors_sum, true, false);
		int sum_factors_sum = 0;
		for (auto factor : sum_factors) {
			sum_factors_sum += factor;
		}

		if (i == sum_factors_sum && i != factors_sum) {
			if (std::find(amicable_numbers.begin(), amicable_numbers.end(), i) == amicable_numbers.end()) {
				amicable_numbers.push_back(i);
				amicable_numbers.push_back(factors_sum);
			}
		}
	}

	for (auto number : amicable_numbers) {
		res += number;
	}

	std::cout << "Result: " << res << std::endl;
	return 0;
}

