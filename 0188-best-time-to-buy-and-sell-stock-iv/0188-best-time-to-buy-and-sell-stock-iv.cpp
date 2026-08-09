class Solution {
private:
    int Rec(vector<int>& prices, int n, int ind, int buy, int k) {
        if (ind >= n)
            return 0;
        if (buy >= k)
            return 0;

        // Buy
        if (buy % 2 == 0) {
            int take = -prices[ind] + Rec(prices, n, ind + 1, buy + 1, k);
            int dontTake = Rec(prices, n, ind + 1, buy, k);
            return max(take, dontTake);
        }
        // Sell
        else {
            int sell = prices[ind] + Rec(prices, n, ind + 1, buy + 1, k);
            int dontsell = Rec(prices, n, ind + 1, buy, k);
            return max(sell, dontsell);
        }
    }

    int Mem(vector<int>& prices, int n, int ind, int buy, int k,
            vector<vector<int>>& dp) {
        if (ind >= n)
            return 0;
        if (buy >= k)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        // Buy
        if (buy % 2 == 0) {
            int take = -prices[ind] + Mem(prices, n, ind + 1, buy + 1, k, dp);
            int dontTake = Mem(prices, n, ind + 1, buy, k, dp);
            return dp[ind][buy] = max(take, dontTake);
        }
        // Sell
        else {
            int sell = prices[ind] + Mem(prices, n, ind + 1, buy + 1, k, dp);
            int dontsell = Mem(prices, n, ind + 1, buy, k, dp);
            return dp[ind][buy] = max(sell, dontsell);
        }
    }

    int Tab(vector<int>& prices, int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        for (int j = 0; j <= 2 * k; j++)
            dp[n][j] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][2 * k] = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2 * k; buy++) {
                // Buy
                if (buy % 2 == 0) {
                    int take = -prices[ind] + dp[ind + 1][buy + 1];
                    int dontTake = dp[ind + 1][buy];
                    dp[ind][buy] = max(take, dontTake);
                }
                // Sell
                else {
                    int sell = prices[ind] + dp[ind + 1][buy + 1];
                    int dontsell = dp[ind + 1][buy];
                    dp[ind][buy] = max(sell, dontsell);
                }
            }
        }
        return dp[0][0];
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        // return Rec(prices, n, 0, 0, 2 * k);
        // return Mem(prices, n, 0, 0, 2 * k, dp);
        return Tab(prices, n, k);
    }
};