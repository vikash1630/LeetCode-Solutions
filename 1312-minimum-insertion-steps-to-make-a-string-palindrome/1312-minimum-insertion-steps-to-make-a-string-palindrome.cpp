class Solution {
private:
    int Rec(string s1, string s2, int i, int j) {
        if (i<0 || j<0) return 0;

        if (s1[i] == s2[j]) return 1 + Rec(s1, s2, i - 1, j - 1);
        return max(Rec(s1, s2, i - 1, j), Rec(s1, s2, i, j - 1));
    }
    int Mem(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
        if (i<0 || j<0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) return dp[i][j] = 1 + Mem(s1, s2, i - 1, j - 1, dp);
        return dp[i][j] = max(Mem(s1, s2, i - 1, j, dp), Mem(s1, s2, i, j - 1, dp));
    }
    int Tab(string s1, string s2, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=n;j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
public:
    int minInsertions(string s) {
        string p = s;
        reverse(p.begin(), p.end());
        int n = s.size();
        // return n - Rec(s, p, n - 1, n - 1);
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return n - Mem(s, p, n - 1, n - 1, dp);
        return n - Tab(s, p, n);
    }
};
