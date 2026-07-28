class Solution {
private:
    int Rec(int i, int j1, int j2,int n, int m, vector<vector<int>> &grid) {
        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) {
            return -1e8;
        }
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        int maxi = 0;
        for (int r1 = -1;r1<=1;r1++) {
            for (int r2 = -1;r2<=1;r2++) {
                int points = 0;
                if (j1 == j2) points = grid[i][j1] + Rec(i + 1, j1 + r1, j2 + r2,n, m,  grid);
                else points = grid[i][j1] + grid[i][j2] + Rec(i + 1, j1 + r1,j2 + r2, n, m, grid);
                maxi = max(maxi, points);
            }
        }
        return maxi;
    }

    int Mem(int i, int j1, int j2,int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) {
            return -1e8;
        }
        if (i == n - 1) {
            if (j1 == j2) return dp[i][j1][j2] = grid[i][j1];
            else return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = 0;
        for (int r1 = -1;r1<=1;r1++) {
            for (int r2 = -1;r2<=1;r2++) {
                int points = 0;
                if (j1 == j2) points = grid[i][j1] + Mem(i + 1, j1 + r1, j2 + r2,n, m,  grid, dp);
                else points = grid[i][j1] + grid[i][j2] + Mem(i + 1, j1 + r1,j2 + r2, n, m, grid, dp);
                maxi = max(maxi, points);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        // return Rec(0,0, m - 1, n,m,grid);
        return Mem(0,0, m - 1, n,m,grid, dp);
    }
};