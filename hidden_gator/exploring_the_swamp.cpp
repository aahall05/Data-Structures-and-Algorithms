#include <iostream>
#include <cstdlib>
#include <vector>
bool isValid(std::vector<std::vector<int>>& swamp_maze, int m, int n) {
    if(m < swamp_maze.size() && n < swamp_maze[m].size()) {
		return true;
	}
    return false;
}

int swampExplorer(std::vector<std::vector<int>>& swamp_maze)
{
    // swamp_maze is the 2D grid of the swamp with coffee beans at each location
    // return the max beans that Albert can collect
    
int m = 0, n = 0;
        int rows = swamp_maze.size();
        int beans = swamp_maze[0][0];

        while (m != rows - 1 && n != swamp_maze[rows - 1].size()) {
            /*
                three cases:
                1. if both m + 1 and n + 1 are valid, then choose the one with more beans
                2. if only m + 1 is valid, then move down
                3. if only n + 1 is valid, then move right
            */
            if (isValid(swamp_maze, m + 1, n) && isValid(swamp_maze, m, n + 1)) {
                if (swamp_maze[m][n + 1] > swamp_maze[m + 1][n]) {
                    beans += swamp_maze[m][n + 1];
                    n++;
                } else {
				    beans += swamp_maze[m + 1][n];
				    m++;
			    }
            }
            else if (isValid(swamp_maze, m + 1, n)) {
			    beans += swamp_maze[m + 1][n];
			    m++;
		    } 
            else if (isValid(swamp_maze, m, n + 1)) {
			    beans += swamp_maze[m][n + 1];
			    n++;
		    }
        }
        return beans;

    if(swamp_maze.size() == 0) 
		return 0; 
    else {
        
    }
   
}
