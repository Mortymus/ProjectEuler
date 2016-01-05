#include <iostream>
#include <unordered_map>

long long collatz_sequence_count(long long value) {
	long long res = 1;
	while (value != 1) {
		res++;
		if (value % 2 == 0)
			value = value / 2;
		else
			value = 3 * value + 1;
	}
	return res;
}

int main() {
	std::cout << "Project Euler 14: Longest Collatz sequence" << std::endl;
	long long res;
	long long longest_sequence = 0;

	for (long long i = 1; i < 1000000; i++) {
		long long sequence_count = collatz_sequence_count(i);
		if (sequence_count > longest_sequence) {
			res = i;
			longest_sequence = sequence_count;
		}
	}

	std::cout << "Result: " << res << std::endl;
	return 0;
}

