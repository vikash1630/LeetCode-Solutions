class Solution {
private:
    // Recurssion
    int Recsolve(int n, int m, int r, int c) {
        if (r == n - 1 && c == m - 1) return 1;

        int right = 0;
        int down = 0;
        // Go right
        if (c + 1 < m) {
            right = Recsolve(n, m , r, c + 1);
        }

        // Go left
        if (r + 1 < n) {
            down = Recsolve(n, m, r + 1, c);
        }

        return right + down;

    }

    // Memoization
    int Memsolve(int n, int m, int r, int c, vector<vector<int>> &dp) {
        if (r == n - 1 && c == m - 1) return dp[r][c] = 1;
        if (dp[r][c] != -1) return dp[r][c];
        int right = 0;
        int down = 0;
        // Go right
        if (c + 1 < m) {
            right = Memsolve(n, m , r, c + 1, dp);
        }

        // Go left
        if (r + 1 < n) {
            down = Memsolve(n, m, r + 1, c, dp);
        }

        return dp[r][c] = right + down; 
    }

    // Tabulation
    int tab(int n, int m) {
        vector<vector<int>> dp(n ,vector<int>(m, -1));
        dp[n - 1][m - 1] = 1;
        for (int row = n - 1;row >= 0;row--) {
            for (int col = m - 1;col >= 0;col--) {
                // If computed then ignore
                if (dp[row][col] != -1) continue;
                int right = 0;
                if (col + 1 < m) right = dp[row][col + 1];
                int down = 0;
                if (row + 1 < n) down = dp[row + 1][col];
        
                dp[row][col] = right + down;
            }
        }
        return dp[0][0];
    }

    // space optimization
    int opt(int n, int m) {
        // we only need 2 rows
        // current row and next row
        vector<int> nextRow(m, 0);
        for (int row = n - 1;row >= 0;row--) {
            vector<int> curRow(m, -1);
            for (int col = m - 1;col >= 0;col--) {
                // Base case
                if (row == n - 1 && col == m - 1) {
                    curRow[col] = 1;
                    continue;
                }
                int right = 0;
                if (col + 1 < m) right = curRow[col + 1];
                int down = 0;
                if (row + 1 < n) down = nextRow[col];

                curRow[col] = right + down;
            }
            nextRow = curRow;
        }
        return nextRow[0];
    }
    
    // Most optimal solution
    int optimal(int n, int m) {
        // we only need 2 rows
        // current row and next row
        vector<int> nextRow(m, 0);
        for (int row = n - 1;row >= 0;row--) {
            int next = 0;
            for (int col = m - 1;col >= 0;col--) {
                // Base case
                if (row == n - 1 && col == m - 1) {
                    next = 1;
                    nextRow[col] = next;
                    continue;
                }
                int right = 0;
                if (col + 1 < m) right = next;
                int down = 0;
                if (row + 1 < n) down = nextRow[col];

                next = right + down;
                nextRow[col] = next;
            }
            
        }
        return nextRow[0];
    }

public:
    int uniquePaths(int m, int n) {
        // return Recsolve(n, m, 0, 0);
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // return Memsolve(n,m,0,0,dp);
        // return tab(n, m);
        return optimal(n, m);
    }
};