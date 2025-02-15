#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "AdjacencyList.h"
#include <sstream>
#include <string>

/*
    compile command:  
    g++ -std=c++11 -o testRunner test.cpp AdjacencyList.cpp -I .
    run command: 
    ./testRunner
*/

TEST_CASE("Insertion updates graph correctly", "[given]") {
    AdjacencyList graph;
    graph.insert("A", "B");
    REQUIRE(graph.getSize() == 2);
    REQUIRE(graph.hasEdge("A", "B") == true);
}

TEST_CASE("Initial PageRank values are set correctly", "[given]") {
    AdjacencyList graph;
    graph.insert("A", "B");
    graph.insert("B", "C");
    graph.PageRank(1);
    // todo: maybe change these from literal to approx
    REQUIRE(graph.getPageRank("A") == 0.33);
    REQUIRE(graph.getPageRank("B") == 0.33);
    REQUIRE(graph.getPageRank("C") == 0.33);
}

TEST_CASE("PageRank converges correctly after multiple iterations", "[given]") {
    AdjacencyList graph;
    graph.insert("A", "B");
    graph.insert("B", "A");
    graph.PageRank(10);
    // todo: maybe change from literal to approx
    REQUIRE(graph.getPageRank("A") == 0.50);
    REQUIRE(graph.getPageRank("B") == 0.50);
}

TEST_CASE("PageRank with no incoming links", "[given]") {
    AdjacencyList graph;
    graph.insert("A", "B");
    graph.PageRank(10);
    // todo: maybe change from literal to approx
    REQUIRE(graph.getPageRank("A") == 0.00);
    REQUIRE(graph.getPageRank("B") == 0.00);
}

TEST_CASE("PageRank with no outgoing links", "[given]") {
    AdjacencyList graph;
    graph.insert("A", "B");
    graph.insert("B", "C");
    // Create a cycle
    graph.insert("C", "A");
    // D has no outgoing links
    graph.insert("C", "D"); 
    graph.PageRank(10);
    // todo: maybe change from literal to approx
    REQUIRE(graph.getPageRank("D") == 0.03);
}
