#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


int main() {
	std::cout << "Project Euler 22: Names scores" << std::endl;

	std::vector<std::string> names;

	std::ifstream input;
	input.open("input.txt");
	std::string line;

	std::getline(input, line);

	// First create a vector with all names as strings
	const char separator = '"';

	int start = 0, end = 0;

	int namestart = -1;

	while ((end = line.find(separator, start)) != std::string::npos) {
		if (namestart < 0)
			namestart = end + 1;
		else {
			int count = end - namestart;
			names.push_back(line.substr(namestart, count));
			namestart = -1;
		}
		start = end + 1;
	}

	//Sort names
	std::sort(names.begin(), names.end(), [](std::string &first, std::string &second) {
		for (int i = 0; i < first.length(); i++) {
			if (i >= second.length()) {
				return false;
			}
			if ((int)first[i] < (int)second[i])
				return true;
			if ((int)first[i] > (int)second[i])
				return false;
		}
		return true;
	});

	long long res = 0;

	for (int i = 0; i < names.size(); i++) {
		std::string &name = names[i];
		int sum = 0;
		for (char c : name) {
			sum += c - 'A' + 1;
		}
		res += sum * (i + 1);
	}

	std::cout << "Result: " << res << std::endl;
	return 0;
}

