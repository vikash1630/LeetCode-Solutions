class Solution {
private:
    // Recurrsion
    int Rec(int n, vector<vector<int>>& tri, int r, int ind) {
        if (r == n - 1) {
            return tri[r][ind];
        }

        // Go with i
        int a = tri[r][ind] + Rec(n, tri, r + 1, ind);

        // Go with i + 1
        int b = tri[r][ind] + Rec(n, tri, r + 1, ind + 1);

        return min(a, b);
    }

    // Memoization
    int Mem(int n, vector<vector<int>>& tri, int r, int ind, vector<vector<int>> &dp) {
        if (r == n - 1)
            return tri[r][ind];

        if (dp[r][ind] != -1)
            return dp[r][ind];

        int down = tri[r][ind] + Mem(n, tri, r + 1, ind, dp);
        int diag = tri[r][ind] + Mem(n, tri, r + 1, ind + 1, dp);

        return dp[r][ind] = min(down, diag);

    }

    // Tabulation
    int Tab(int n, vector<vector<int>>& tri, vector<vector<int>>& dp) {

    // Base case
    for (int i = 0; i < dp[n - 1].size(); i++)
        dp[n - 1][i] = tri[n - 1][i];

    // Fill DP from bottom to top
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < tri[i].size(); j++) {

            int down = tri[i][j] + dp[i + 1][j];
            int diag = tri[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diag);
        }
    }

    return dp[0][0];
}

    // Space Optimal
    int opt(int n, vector<vector<int>>& tri) {
        vector<int> dp(n, -1);
        for (int i = 0;i<n;i++) dp[i] = tri[n - 1][i];

        for (int i = n - 2;i>=0;i--) {
            vector<int> arr(i + 1, -1);
            for (int j = 0;j<tri[i].size();j++) {
                int down = tri[i][j] + dp[j];
                int diag = tri[i][j] + dp[j + 1];

                arr[j] = min(down, diag);
            }
            dp.resize(i + 1, -1);
            dp = arr;
        }
        return dp[0];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1) return triangle[0][0];
        // return Rec(n, triangle, 0, 0);
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) dp[i].resize(i + 1, -1);
        // return Mem(n, triangle, 0, 0,dp);
        // return Tab(n, triangle, dp);
        return opt(n, triangle);
    }
};