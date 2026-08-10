class Solution {
private:
    int Rec(string s1, string s2, int i, int j) {
        if (j < 0) return i + 1;
        if (i < 0) return j + 1;

        if (s1[i] == s2[j]) return 0 + Rec(s1, s2, i - 1, j - 1);

        int insert = 1 + Rec(s1, s2, i, j - 1);
        int del = 1 + Rec(s1, s2, i - 1, j);
        int rep = 1 + Rec(s1, s2, i - 1, j - 1);
        return min(insert, min(del, rep));
    }

    int Mem(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
        if (j < 0) return i + 1;
        if (i < 0) return j + 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) return dp[i][j] = 0 + Mem(s1, s2, i - 1, j - 1, dp);

        int insert = 1 + Mem(s1, s2, i, j - 1, dp);
        int del = 1 + Mem(s1, s2, i - 1, j, dp);
        int rep = 1 + Mem(s1, s2, i - 1, j - 1, dp);
        return dp[i][j] = min(insert, min(del, rep));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // return Rec(word1, word2, n - 1, m - 1);
        vector<vector<int>> dp(n, vector<int>(m, - 1));

        return Mem(word1, word2, n - 1,m - 1, dp);
    }
};