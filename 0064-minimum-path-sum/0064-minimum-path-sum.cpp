class Solution {
private:
    int RecSol(int n, int m, int r, int c, vector<vector<int>> &grid) {
        if (r == n - 1 && c == m - 1) return grid[r][c];

        // Go right
        int right = INT_MAX;
        if (c + 1 < m) right = grid[r][c] + RecSol(n , m , r, c + 1, grid);

        // Go Down 
        int down = INT_MAX;
        if (r + 1 < n) down = grid[r][c] + RecSol(n, m, r + 1, c, grid);

        return min(right, down);
    }

    // Memoization
    int memSol(int n, int m, int r , int c, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if (r == n - 1 && c == m - 1) return dp[n - 1][m - 1] = grid[n - 1][m - 1];

        if (dp[r][c] != -1) return dp[r][c];
        // Go Right
        int right = INT_MAX;
        if (c + 1 < m) right = grid[r][c] + memSol(n, m, r, c + 1, grid, dp);

        // Go down
        int down = INT_MAX;
        if (r + 1 < n) down = grid[r][c] + memSol(n, m, r + 1, c, grid, dp);

        return dp[r][c] = min(right, down);
    }

    // Tabulation solution
    int tab(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n - 1][m - 1] = grid[n - 1][m - 1];
        for (int row = n - 1;row >= 0;row--) {
            for (int col = m - 1;col >=0; col--) {
                if (row == n - 1 && col == m - 1) continue;
                int right = INT_MAX;
                if (col + 1 < m) right = grid[row][col] + dp[row][col + 1];
                int down = INT_MAX;
                if (row + 1 < n) down = grid[row][col] + dp[row + 1][col];

                dp[row][col] = min(right, down);
            }
        }
        return dp[0][0];
    }

    // space optimal
    int opt(int n, int m, vector<vector<int>> &grid) {
        
        vector<int> nextRow(m, 0);
        for (int row = n - 1;row >= 0;row--) {
            vector<int> curRow(m, 0);
            for (int col = m - 1;col >=0; col--) {
                if (row == n - 1 && col == m - 1) {
                    nextRow[col] = grid[row][col];
                    curRow[col] = grid[row][col];
                    continue;
                }
                int right = INT_MAX;
                if (col + 1 < m) right = grid[row][col] + curRow[col + 1];
                int down = INT_MAX;
                if (row + 1 < n) down = grid[row][col] + nextRow[col];

                curRow[col] = min(right, down);
            }
            nextRow = curRow;
        }
        return nextRow[0];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && m == 1) return grid[0][0];
        // return RecSol(n, m, 0, 0, grid);
        vector<vector<int>> dp(n, vector<int>(m , -1));
        // return memSol(n, m, 0, 0, grid, dp);
        // return tab(n, m, grid);
        return opt(n, m, grid);
    }
};