#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <set>

struct Position {
    int x, y, steps;
};

int traverse(std::vector<std::string>& graph) {

    // use BFS to find shortest path

    // rows and cols for easy typing
    int rows = graph.size();
    int cols = graph[0].size();
    std::set<std::pair<int, int>> visited;
    std::queue<Position> q;

    // initialize start position
    q.push({ 0, 0, 0 });
    visited.insert({ 0, 0 });

    // directions for up, down, left, right
    std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while (!q.empty()) {
        Position current = q.front();
        q.pop();

        // if current position is the botom right corner, return steps
        if (current.x == rows - 1 && current.y == cols - 1) {
            return current.steps;
        }

        // explore all four directions
        for (const auto& dir : directions) {
            int newX = current.x + dir.first;
            int newY = current.y + dir.second;

            // check if new position is a valid coordinate, is not in visited, and not '#'
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && visited.count({ newX, newY }) == 0 && graph[newX][newY] != '#') {
                // add new position to q and visited
                q.push({ newX, newY, current.steps + 1 });
                visited.insert({ newX, newY });
            }
        }
    }

    // if this is reached, there is no path from 's' to 't'
    return -1;
}
