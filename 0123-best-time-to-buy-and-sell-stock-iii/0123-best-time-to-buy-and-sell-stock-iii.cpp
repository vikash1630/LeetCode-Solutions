class Solution {
private:
    int Rec(vector<int>& prices,int n, int ind, int buy) {
        if (ind >= n) return 0;
        if (buy >= 4) return 0;
        // First Buy
        if (buy == 0) {
            int take = Rec(prices, n, ind + 1, buy + 1) - prices[ind];
            int dontTake = Rec(prices, n, ind + 1, buy);
            return max(take, dontTake);
        }
        // First Sell
        else if (buy == 1) {
            int sell = prices[ind] + Rec(prices, n, ind + 1, buy + 1);
            int dontsell = Rec(prices, n, ind + 1, buy);
            return max(sell, dontsell);
        }
        // second Buy
        else if (buy == 2) {
            int take = Rec(prices, n, ind + 1, buy + 1) - prices[ind];
            int dontTake = Rec(prices, n, ind + 1, buy);
            return max(take, dontTake);
        }
        // Second Sell
        else {
            int sell = prices[ind] + Rec(prices, n, ind + 1, buy + 1);
            int dontsell = Rec(prices, n, ind + 1, buy);
            return max(sell, dontsell);
        }
    }

    int Mem(vector<int>& prices,int n, int ind, int buy, vector<vector<int>> &dp) {
        if (ind >= n) return 0;
        if (buy >= 4) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];
        // First Buy
        if (buy == 0) {
            int take = Mem(prices, n, ind + 1, buy + 1, dp) - prices[ind];
            int dontTake = Mem(prices, n, ind + 1, buy, dp);
            return dp[ind][buy] = max(take, dontTake);
        }
        // First Sell
        else if (buy == 1) {
            int sell = prices[ind] + Mem(prices, n, ind + 1, buy + 1, dp);
            int dontsell = Mem(prices, n, ind + 1, buy, dp);
            return dp[ind][buy] = max(sell, dontsell);
        }
        // second Buy
        else if (buy == 2) {
            int take = Mem(prices, n, ind + 1, buy + 1, dp) - prices[ind];
            int dontTake = Mem(prices, n, ind + 1, buy, dp);
            return dp[ind][buy] = max(take, dontTake);
        }
        // Second Sell
        else {
            int sell = prices[ind] + Mem(prices, n, ind + 1, buy + 1, dp);
            int dontsell = Mem(prices, n, ind + 1, buy, dp);
            return dp[ind][buy] = max(sell, dontsell);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        // return Rec(prices, n, 0, 0);
        return Mem(prices, n, 0, 0, dp);
    }
};