class Solution {
    int Rec(vector<int>& prices, int ind, int n, int buy) {
        if (ind >= n)
            return 0;

        // Buy
        if (buy % 2 == 0) {
            int take = -prices[ind] + Rec(prices, ind + 1, n, buy + 1);
            int donttake = Rec(prices, ind + 1, n, buy);
            return max(take, donttake);
        }
        // Sell
        else {
            int sell = prices[ind] + Rec(prices, ind + 2, n, buy + 1);
            int dontsell = Rec(prices, ind + 1, n, buy);
            return max(sell, dontsell);
        }
    }

    int Mem(vector<int>& prices, int ind, int n, int buy,
            vector<vector<int>>& dp) {
        if (ind >= n)
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        // Buy
        if (buy % 2 == 0) {
            int take = -prices[ind] + Mem(prices, ind + 1, n, buy + 1, dp);
            int donttake = Mem(prices, ind + 1, n, buy, dp);
            return dp[ind][buy] = max(take, donttake);
        }
        // Sell
        else {
            int sell = prices[ind] + Mem(prices, ind + 2, n, buy + 1, dp);
            int dontsell = Mem(prices, ind + 1, n, buy, dp);
            return dp[ind][buy] = max(sell, dontsell);
        }
    }

    int Tab(vector<int>& prices, int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < n; buy++) {
                // Buy
                if (buy % 2 == 0) {
                    int take = -prices[ind] + dp[ind + 1][buy + 1];
                    int donttake = dp[ind + 1][buy];
                    dp[ind][buy] = max(take, donttake);
                }
                // Sell
                else {
                    int sell = prices[ind] + dp[ind + 2][buy + 1];
                    int dontsell = dp[ind + 1][buy];
                    dp[ind][buy] = max(sell, dontsell);
                }
            }
        }
        return dp[0][0];
    }

    int opt(vector<int>& prices, int n) {
        vector<int> dp1(n + 1, 0);
        vector<int> dp2(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            vector<int> dum(n + 1, 0);
            for (int buy = 0; buy < n; buy++) {
                // Buy
                if (buy % 2 == 0) {
                    int take = -prices[ind] + dp1[buy + 1];
                    int donttake = dp1[buy];
                    dum[buy] = max(take, donttake);
                }
                // Sell
                else {
                    int sell = prices[ind] + dp2[buy + 1];
                    int dontsell = dp1[buy];
                    dum[buy] = max(sell, dontsell);
                }
            }
            dp2 = dp1;
            dp1 = dum;
        }
        return dp1[0];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // return Rec(prices, 0, n, 0);
        // vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        // return Mem(prices, 0, n, 0, dp);
        // return Tab(prices, n);
        return opt(prices, n);
    }
};