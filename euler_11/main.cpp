#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void setResultIfLarger(int value, int& res) {
	if (value > res)
		res = value;
}

int main() {
	std::cout << "Project Euler 11: Largest product in a grid" << std::endl;
	int res = 0;

	const int grid_dimension = 20;

	int grid[grid_dimension][grid_dimension];

	std::ifstream input_stream;
	input_stream.open("input.txt");
	std::string line;
	int row = 0, col = 0;

	//Read the grid from the input file
	while (std::getline(input_stream, line)) {
		col = 0;
		std::istringstream iss(line);
		int n;
		while (iss >> n) {
			grid[row][col] = n;
			col++;
		}
		row++;
	}
	int limit = grid_dimension - 3;
	for (int i = 3; i < limit; i++) {
		for (int j = 3; j < limit; j++) {
			//Check left
			setResultIfLarger(grid[i][j - 3] * grid[i][j - 2] * grid[i][j - 1] * grid[i][j], res);
			//Check right
			setResultIfLarger(grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3], res);
			//Check top
			setResultIfLarger(grid[i][j] * grid[i - 1][j] * grid[i - 2][j] * grid[i - 3][j], res);
			//Check bottom
			setResultIfLarger(grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j], res);
			//Check top left
			setResultIfLarger(grid[i][j] * grid[i - 1][j - 1] * grid[i - 2][j - 2] * grid[i - 3][j - 3], res);
			//Check top right
			setResultIfLarger(grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3], res);
			//Check bottom left
			setResultIfLarger(grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3], res);
			//Check bottom right
			setResultIfLarger(grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3], res);
		}
	}

	std::cout << "Result: " << res << std::endl;
	return 0;
}

