#include <bits/stdc++.h>
using namespace std;

int islandPerimeter(vector<vector<int>> &grid)
{
    int perimeter = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == 1)
            {
                perimeter += 4;
                if (r > 0 && grid[r - 1][c] == 1)
                {
                    perimeter -= 2;
                }
                if (c > 0 && grid[r][c - 1] == 1)
                {
                    perimeter -= 2;
                }
            }
        }
    }

    return perimeter;
}
int main()
{
    vector<vector<int>> g = {{0, 1, 0, 0},
                             {1, 1, 1, 0},
                             {0, 1, 0, 0},
                             {1, 1, 0, 0}};
    vector<vector<int>> g1 = {{1}};
    cout << islandPerimeter(g) << endl;
    return 0;
}