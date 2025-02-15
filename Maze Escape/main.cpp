#include <iostream>
#include <vector>
#include "maze_escape.h"

int main() {
    std::vector<std::string> maze = {
        "s....",
        ".....",
        "....t"
    };

    int result = traverse(maze);
    std::cout << "Shortest path length: " << result << std::endl;

    return 0;
}