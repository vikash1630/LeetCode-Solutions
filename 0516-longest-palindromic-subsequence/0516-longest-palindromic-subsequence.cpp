class Solution {
private:
    int Rec(string s1, string s2, int i, int j) {
        if (i < 0 || j < 0)
            return 0;

        if (s1[i] == s2[j])
            return 1 + Rec(s1, s2, i - 1, j - 1);

        return max(
            Rec(s1, s2, i - 1, j),
            Rec(s1, s2, i, j - 1)
        );
    }

    int Mem(string s1, string s2, int i, int j,
            vector<vector<int>>& dp) {

        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + Mem(s1, s2, i - 1, j - 1, dp);

        return dp[i][j] = max(
            Mem(s1, s2, i - 1, j, dp),
            Mem(s1, s2, i, j - 1, dp)
        );
    }

    int Tab(string s1, string s2, int n) {
        vector<int> dp(n + 1, -1);
        for (int i = 0;i<=n;i++) {
            dp[i] = 0;
        }

        for (int i = 1;i<=n;i++) {
            vector<int> dum(n + 1, 0);
            for (int j = 1;j<=n;j++) {
                if (s1[i - 1] == s2[j - 1]) dum[j] = 1 + dp[j - 1];
                else {
                    dum[j] = max(dp[j], dum[j - 1]);
                }
            }
            dp = dum;
        }
        return dp[n];
    }

public:
    int longestPalindromeSubseq(string s) {
        string c = s;
        reverse(c.begin(), c.end());

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        // return Mem(c, s, n - 1, n - 1, dp);
        return Tab(s, c, n);
    }
};

