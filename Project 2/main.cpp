#include <iostream>
#include <string>
#include "AdjacencyList.h"
#include <sstream>
#include "parseInput.h"


int main() {

    // todo: DELETE THIS
    /*for (int i = 1; i <= 1000; ++i) {
        std::cout << "Site" << std::to_string(i) << " " << "Site" << std::to_string((i % 1000) + 1) << std::endl;
    }*/

	int no_of_lines, power_iterations;
	AdjacencyList Created_Graph;

	std::string from, to;

	std::cin >> no_of_lines;

	std::cin >> power_iterations;

	for (int i = 0; i < no_of_lines; i++)
	{
		std::cin >> from;
		std::cin >> to;

		Created_Graph.insert(from, to);
	}
	//Create a graph object
	Created_Graph.PageRank(power_iterations);

}

std::string parseInput(const std::string& input) {
    std::istringstream in(input);
    std::ostringstream out;
    std::streambuf* coutbuf = std::cout.rdbuf(); // Save old buf
    std::cout.rdbuf(out.rdbuf()); // Redirect std::cout to out.rdbuf()

    std::string from, to;
    int no_of_lines, power_iterations;
    in >> no_of_lines >> power_iterations;

    AdjacencyList Created_Graph;

    for (int i = 0; i < no_of_lines; i++) {
        in >> from >> to;
        Created_Graph.insert(from, to);
    }

    Created_Graph.PageRank(power_iterations);

    std::cout.rdbuf(coutbuf); // Reset to standard output again

    return out.str();
}