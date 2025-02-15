#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <cmath>

class AdjacencyList {
private:
    /*
        graph has a string key and a pair of vectors of strings as its value.
        the first vector represents the websites that it points to,
        and the second vector represents the websites that point to it.
    */ 
    std::map<std::string, std::pair<std::vector<std::string>, std::vector<std::string>>> graph;
    std::map<std::string, double> pageRank;
    int size = 0;

public:
    AdjacencyList();

    /* Functions */
    void insert(std::string from, std::string to = "");
    void PageRank(int n);

    // for testing purposes
    int getSize() {return size;}
    double getPageRank(std::string page);
    bool hasEdge(std::string from, std::string to);
};
