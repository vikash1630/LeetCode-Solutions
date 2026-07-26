class Solution {
private:
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
public:
    int uniquePaths(int m, int n) {
        // return Recsolve(n, m, 0, 0);
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return Memsolve(n,m,0,0,dp);
    }
};