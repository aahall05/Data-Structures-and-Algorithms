#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

class Graph
{
private:

    // one vertex can point to the same 'to' multiple times
    std::map<int, std::vector<std::pair<int,int>>> graph;

public:
    void insertEdge(int from, int to, int weight);
    bool isEdge(int from, int to);
    int sumEdge(int from, int to);
    std::vector<int> getWeight(int from, int to);
    std::vector<int> getAdjacent(int vertex);
};

void Graph::insertEdge(int from, int to, int weight)
{
    // if from vertex is not in the graph, add it
    if(graph.find(from) == graph.end())
		graph[from] = std::vector<std::pair<int,int>>();

	// pushback 'to' and weight
    graph[from].push_back(std::make_pair(to, weight));
}

bool Graph::isEdge(int from, int to)
{
    // check if 'from' is in graph
    if (graph.find(from) != graph.end()){
        // iterate through the vector of pairs
        for(auto i : graph[from])
			if(i.first == to)
				return true;
    }

    return false;
}

int Graph::sumEdge(int from, int to)
{
    int sum = 0;
 
    // check if 'from' is in graph
    if (graph.find(from) != graph.end()) {
        for (auto i : graph[from])
            if (i.first == to)
                sum += i.second;
    }

    return sum;
}

std::vector<int> Graph::getWeight(int from, int to)
{
    /*
        getWeight() returns a sorted vector containing all
        weights of the edges connecting the from and to vertex
    */
    std::vector<int> weights;

    // check if 'from' is in graph
    if (graph.find(from) != graph.end()) {
        // iterate through the vector of pairs adding weight to vector
        for(auto it : graph[from])
            if(it.first == to)
			    weights.push_back(it.second);
        std::sort(weights.begin(), weights.end());
    }

    return weights;
}

std::vector<int> Graph::getAdjacent(int vertex)
{
    /*
        getAdjacent() returns a sorted vector of all vertices
        that are connected to a vertex
    */
    std::vector<int> adjacent;
    // check if 'vertex' is in graph
    if (graph.find(vertex) != graph.end()) {
		// iterate through the vector of pairs adding adjacent to vector
		for (auto i : graph[vertex])
			adjacent.push_back(i.first);
        std::sort(adjacent.begin(), adjacent.end());
	}

    return adjacent;
}


