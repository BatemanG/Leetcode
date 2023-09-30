/**
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
**/ 


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int row = 0; row < n; row++) {
                for (int col = 0; col < m; col++) {
                    if(row == 0 && col == 0) grid[row][col] = grid[row][col];
                    else if(row == 0 && col != 0) grid[row][col] = grid[row][col] + grid[row][col - 1];
                    else if(col == 0 && row != 0) grid[row][col] = grid[row][col] + grid[row - 1][col];
                    else grid[row][col] = grid[row][col] + min(grid[row - 1][col], grid[row][col - 1]);
                }
            }
            return grid[n - 1][m - 1]; 
    }
};
