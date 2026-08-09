class Solution {
private:
    int Rec(vector<int>& prices, int n, int ind) {
        if (ind == n) return 0;

        return max(prices[ind], Rec(prices, n, ind + 1));

    }
    int Mem(vector<int>& prices, int n, int ind, vector<int> &dp) {
        if (ind == n) return 0;
        if (dp[ind] != -1) return dp[ind];
        return dp[ind] = max(prices[ind], Mem(prices, n, ind + 1, dp));

    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        vector<int> dp(n, -1);
        for (int i = 0;i<n - 1;i++) {
            int profit = Mem(prices, n, i + 1, dp) - prices[i];
            ans = max(ans, profit);
        }
        return ans;
    }
};