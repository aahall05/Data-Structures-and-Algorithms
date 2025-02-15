//#include <vector>
#include <iostream>
#include "exploring_the_swamp.h"

int main() {
	std::vector<std::vector<int>> swamp_maze = { {1} };
	// {3, 3}, {5, 3, 4}, {8, 6, 9}, {1, 3, 2}
	// {2, 2}, {0, 0}, {1, 0}
	int result = swampExplorer(swamp_maze);

	std::cout << result;
	return 0;
}