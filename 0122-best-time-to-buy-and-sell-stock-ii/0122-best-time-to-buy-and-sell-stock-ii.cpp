class Solution {
private:
    int Rec(vector<int>& prices, int ind, int n, int buy) {
        if (ind == n) return 0;

        long profit = 0;
        // We Can buy
        if (buy == 0) {
            profit = max(0 + Rec(prices, ind + 1, n, buy), -prices[ind] + Rec(prices, ind + 1, n, buy + 1));
        }
        // We can sell
        else {
            profit = max(0 + Rec(prices, ind + 1, n, buy), prices[ind] + Rec(prices, ind + 1, n, buy - 1));
        }
        return profit;
    }
    int Mem(vector<int>& prices, int ind, int n, int buy, vector<vector<long>> &dp) {
        if (ind == n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];
        long profit = 0;
        // We Can buy
        if (buy == 0) {
            profit = max(0 + Mem(prices, ind + 1, n, buy, dp), -prices[ind] + Mem(prices, ind + 1, n, buy + 1, dp));
        }
        // We can sell
        else {
            profit = max(0 + Mem(prices, ind + 1, n, buy, dp), prices[ind] + Mem(prices, ind + 1, n, buy - 1, dp));
        }
        return dp[ind][buy] = profit;
    }

    int Tab(vector<int>& prices, int ind, int n, int buy, vector<vector<long>> &dp) {
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int i = n - 1;i>=0;i--) {
            long profit = 0;
            for (int buy = 0;buy<=1;buy++) {
                // We Can buy
                if (buy == 0) {
                    profit = max(0 + dp[i + 1][buy], -prices[i] + dp[i + 1][buy + 1]);
                }
                // We can sell
                else {
                    profit = max(0 + dp[i + 1][buy], prices[i] + dp[i + 1][buy - 1]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][0];
    }

    int opt(vector<int>& prices, int n) {
        vector<int> dp(2, 0);
        
        for (int i = n - 1;i>=0;i--) {
            long profit = 0;
            vector<int> dum(2, 0);
            for (int buy = 0;buy<=1;buy++) {
                // We Can buy
                if (buy == 0) {
                    profit = max(0 + dp[buy], -prices[i] + dp[buy + 1]);
                }
                // We can sell
                else {
                    profit = max(0 + dp[buy], prices[i] + dp[buy - 1]);
                }
                dum[buy] = profit;
            }
            dp = dum;
        }
        return dp[0];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // return Rec(prices, 0, n, 0);
        // vector<vector<long>> dp(n + 1, vector<long>(2, -1));
        // return Mem(prices, 0, n, 0, dp);
        // return Tab(prices, 0, n, 0, dp);
        return opt(prices, n);
    }
};