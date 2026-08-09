class Solution {
private:
    int Rec(vector<int>& prices, int ind, int n, int buy) {
        if (ind == n) return 0;

        long profit = 0;
        // We Can buy
        if (buy == 0) {
            profit = max(0 + Rec(prices, ind + 1, n, buy), -prices[ind] + Rec(prices, ind + 1, n, buy - 1));
        }
        // We can sell
        else {
            profit = max(0 + Rec(prices, ind + 1, n, buy), prices[ind] + Rec(prices, ind + 1, n, buy + 1));
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
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // return Rec(prices, 0, n, 0);
        vector<vector<long>> dp(n, vector<long>(2, -1));
        return Mem(prices, 0, n, 0, dp);
    }
};