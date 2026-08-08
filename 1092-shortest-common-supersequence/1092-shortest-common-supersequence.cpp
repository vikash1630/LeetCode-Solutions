class Solution {
private:
    string buildSCS(string s1, string s2, vector<vector<int>>& dp) {

        int i = s1.size();
        int j = s2.size();

        string ans;

        while (i > 0 && j > 0) {

            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += s1[i - 1];
                i--;
            }
            else {
                ans += s2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            ans += s1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += s2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j],
                                   dp[i][j - 1]);
                }
            }
        }

        return buildSCS(str1, str2, dp);
    }
};