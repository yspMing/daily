#pragma once
#include<vector>
#include<iostream>

using std::vector;

static void fillWater(vector<vector<int>>& grid, int i, int j)
{
    int m = grid.size();
    int n = grid[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n) return; //  out of map
    if (0 == grid[i][j]) return; // reach island edge

    grid[i][j] = 0; //fill water

    fillWater(grid, i - 1, j);
    fillWater(grid, i + 1, j);
    fillWater(grid, i, j - 1);
    fillWater(grid, i, j + 1);
}

int numIsLands(vector<vector<int>>& grid)
{
    int m = grid.size();
    if (m < 1) {
        return 0;
    }
    int n = grid[0].size();
    if (n < 1) {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
        {
            if (1 == grid[i][j]) {
                count++;
                fillWater(grid, i, j); // fill water for the whole island
            }
        }
    }

    return count;
}

void runNumIslands()
{
    std::cout << "=======>runNumIslands" << std::endl;
    vector<vector<int> > vec;
    vector<int> v1 = { 1,1,0,0,0 };
    vector<int> v2 = { 1,1,0,0,0 };
    vector<int> v3 = { 0,0,1,0,0 };
    vector<int> v4 = { 0,0,0,1,1 };
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);
    vec.push_back(v4);

    std::cout << "numner of islands: "<<numIsLands(vec)<<std::endl;
}