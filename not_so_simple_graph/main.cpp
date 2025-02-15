#include <iostream>
#include "graph.h"

int main() {

    int no_of_lines, power_iterations;
    Graph Created_Graph;

    std::string from, to, weight;
    std::string command;

    std::cin >> no_of_lines;

    for (int i = 0; i < no_of_lines; i++)
    {
        std::cin >> command;
        
        switch (stoi(command))
        {
        case 1:
            std::cin >> from;
            std::cin >> to;
            std::cin >> weight;
            Created_Graph.insertEdge(stoi(from), stoi(to), stoi(weight));
			break;
        case 2:
            std::cin >> from;
            std::cin >> to;
            Created_Graph.insertEdge(stoi(from), stoi(to), stoi(weight));
            break;
        case 3:
            std::cin >> from;
            std::cin >> to;
            Created_Graph.sumEdge(stoi(from), stoi(to));
            break;
        case 4:
            std::cin >> from;
            std::cin >> to;
            Created_Graph.getWeight(stoi(from), stoi(to));
            break;
        case 5:
            std::cin >> from;
			Created_Graph.getAdjacent(stoi(from));
			break;
        default:
            break;
        }
    }

    
    std::cout << std::endl;
}
