class Solution {
private:
    int f(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        for (int ind = i; ind <= j; ind++) {
            int sum = cuts[j + 1] - cuts[i - 1] + f(cuts, i, ind - 1, dp) +
                      f(cuts, ind + 1, j, dp);
            mini = min(sum, mini);
        }
        return dp[i][j] = mini;
    }
    int f(vector<int>& cuts, int c) {
        int dp[c][c];
        for (int i = c - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++)
                dp[i][j] = 0;
        }

        for (int i = c - 2; i >= 1; i--) {
            for (int j = i; j <= c - 2; j++) {
                int mini = 1e9;
                for (int ind = i; ind <= j; ind++) {
                    int sum = cuts[j + 1] - cuts[i - 1] +
                              dp[i][ind - 1] + dp[ind + 1][j];
                    mini = min(sum, mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c-2];
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f(cuts, 1, cuts.size() - 2, dp);
        int c = cuts.size();
        return f(cuts, c);
    }
};