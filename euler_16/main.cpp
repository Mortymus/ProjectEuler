#include <iostream>
#include <vector>

int main() {
	std::cout << "Project Euler 16: Power digit sum" << std::endl;
	int res = 0;

	std::vector<char> result;
	result.push_back((char)2);

	for (int i = 1; i < 1000; i++) {
		bool carry = false;
		for (auto it = result.begin(); it != result.end(); it++) {
			auto next = it + 1;
			char current = *it;
			current *= 2;
			if (carry)
				current++;
			carry = false;
			*it = current % 10;
			if (current >= 10) {
				if (next == result.end()) {
					result.push_back((char)1);
					break;
				}
				else {
					carry = true;
				}
			}
		}
	}

	for (auto digit : result) {
		res += digit;
	}

	std::cout << "Result: " << res << std::endl;
	return 0;
}

