class Solution {
private:
    // Recurssion
    int recSolve(int n, int m, vector<vector<int>>& obstacleGrid, int r, int c) {
        if (r == n - 1 && c == m - 1) return 1;
        if (obstacleGrid[r][c] == 1) return 0;

        // Go right
        int right = 0;
        if (c + 1 < m) right = recSolve(n,m,obstacleGrid, r, c + 1);

        // Go down
        int down = 0;
        if (r + 1 < n) down = recSolve(n,m,obstacleGrid, r + 1, c);

        return right + down;
    }

    // memoization
    int mem(int n, int m, vector<vector<int>>& obstacleGrid, int r, int c, vector<vector<int>> &dp) {
        if (r == n - 1 && c == m - 1) return dp[r][c] = 1;
        if (obstacleGrid[r][c] == 1) return dp[r][c] = 0;

        if (dp[r][c] != -1) return dp[r][c];

        // Go right
        int right = 0;
        if (c + 1 < m) right = mem(n,m,obstacleGrid, r, c + 1, dp);

        // Go down
        int down = 0;
        if (r + 1 < n) down = mem(n,m,obstacleGrid, r + 1, c, dp);

        return dp[r][c] = right + down;
    }

    // Tabulation
    int tab(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n - 1][m - 1] = 1;
        for (int row = n - 1;row >=0;row--) {
            for (int col = m - 1;col>=0;col--) {
                if (row == n - 1 && col == m - 1) continue;
                if (grid[row][col] == 1) {
                    dp[row][col] = 0;
                    continue;
                }
                long long right = 0;
                if (col + 1 < m) right = dp[row][col + 1];
                long long down = 0;
                if (row + 1 < n) down = dp[row + 1][col];

                dp[row][col] = right + down;
            }
        }
        return dp[0][0];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) return 0;
        // return recSolve(n , m, obstacleGrid, 0, 0);
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // return mem(n, m, obstacleGrid, 0, 0, dp);
        return tab(n, m, obstacleGrid);
    }
};