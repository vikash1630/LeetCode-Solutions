class Solution {
private:
    int Rec(string s1, string s2, int i, int j) {
        if (j < 0)
            return i + 1;
        if (i < 0)
            return j + 1;

        if (s1[i] == s2[j])
            return 0 + Rec(s1, s2, i - 1, j - 1);

        int insert = 1 + Rec(s1, s2, i, j - 1);
        int del = 1 + Rec(s1, s2, i - 1, j);
        int rep = 1 + Rec(s1, s2, i - 1, j - 1);
        return min(insert, min(del, rep));
    }

    int Mem(string s1, string s2, int i, int j, vector<vector<int>>& dp) {
        if (j < 0)
            return i + 1;
        if (i < 0)
            return j + 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
            return dp[i][j] = 0 + Mem(s1, s2, i - 1, j - 1, dp);

        int insert = 1 + Mem(s1, s2, i, j - 1, dp);
        int del = 1 + Mem(s1, s2, i - 1, j, dp);
        int rep = 1 + Mem(s1, s2, i - 1, j - 1, dp);
        return dp[i][j] = min(insert, min(del, rep));
    }

    int Tab(string s1, string s2, int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 0 + dp[i - 1][j - 1];
                else {
                    int insert = 1 + dp[i][j - 1];
                    int del = 1 + dp[i - 1][j];
                    int rep = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min(insert, min(del, rep));
                }
            }
        }
        return dp[n][m];
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // return Rec(word1, word2, n - 1, m - 1);
        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // return Mem(word1, word2, n - 1, m - 1, dp);
        return Tab(word1, word2, n, m);
    }
};