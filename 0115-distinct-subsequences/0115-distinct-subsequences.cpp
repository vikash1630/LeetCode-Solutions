class Solution {
int Rec(string s, string t, int i, int j) {
    if (j < 0) return 1;
    if (i < 0) return 0;
    if (s[i] == t[j]) {
        int take = Rec(s, t, i - 1, j - 1);
        int dontTake = Rec(s, t, i - 1, j);
        return take + dontTake;
    }
    else {
        int move = Rec(s, t, i - 1, j);
        return move;
    }
}

int Mem(string s, string t, int i, int j, vector<vector<int>> &dp) {
    if (j < 0) return 1;
    if (i < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == t[j]) {
        int take = Mem(s, t, i - 1, j - 1, dp);
        int dontTake = Mem(s, t, i - 1, j, dp);
        return dp[i][j] = take + dontTake;
    }
    else {
        int move = Mem(s, t, i - 1, j, dp);
        return dp[i][j] = move;
    }
}

int Tab(string s, string t, int n, int m) {
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1 , 0));
    for (int j = 0;j<=m;j++) dp[0][j] = 0;
    for (int i = 0;i<=n;i++) dp[i][0] = 1;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            if (s[i - 1] == t[j - 1]) {
                long long take = dp[i - 1][j - 1];
                long long donttake = dp[i - 1][j];
                dp[i][j] = min(1LL * INT_MAX, take + donttake);
            }
            else {
                long long move = dp[i - 1][j];
                dp[i][j] = move;
            }
        }
    }
    return dp[n][m];
}

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // return Rec(s, t, n - 1, m - 1);
        vector<vector<int>> dp(n, vector<int>(m , -1));

        // return Mem(s, t, n - 1, m - 1, dp);
        return Tab(s, t, n, m);
    }
};