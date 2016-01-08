#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

typedef std::vector<int> level_vector;

int main() {
	std::cout << "Project Euler 18: Maximum path sum I" << std::endl;

	std::ifstream input;
	input.open("input.txt");
	std::string line;

	//First we build up the tree as a vector of vectors.
	std::vector<level_vector> tree;

	while (std::getline(input, line)) {
		std::istringstream iss(line);
		level_vector level;
		int n;
		while (iss >> n) {
			level.push_back(n);
		}
		tree.push_back(level);
	}

	//Iterate over the levels from bottom to top and store intermediate longest paths on the way.
	//Start with the second last level.
	for (int i = tree.size() - 2; i >= 0; i--) {
		auto& current_level = tree[i];
		auto& child_level = tree[i+1];
		//Element iteration in the level
		int level_size = current_level.size();
		for (int j = 0; j < level_size; j++) {
			int left_child = child_level[j];
			int right_child = child_level[j + 1];
			current_level[j] += left_child > right_child ? left_child : right_child;
		}
	}

	std::cout << "Result: " << tree[0][0] << std::endl;
	return 0;
}

