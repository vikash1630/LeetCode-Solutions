class Solution {
    int Rec(vector<int>& coins, int n, int amt, int ind) {

        if (amt == 0) return 0;

        if (ind < 0) return INT_MAX;

        // Don't take current coin
        int dontTake = Rec(coins, n, amt, ind - 1);

        // Take current coin
        int take = INT_MAX;

        if (amt >= coins[ind]) {
            int temp = Rec(coins, n, amt - coins[ind], ind);

            if (temp != INT_MAX)
                take = 1 + temp;
        }

        return min(take, dontTake);
    }

    int Mem(vector<int>& coins, int n, int amt, int ind, vector<vector<int>> &dp) {

        if (amt == 0) return 0;

        if (ind < 0) return INT_MAX;

        if (dp[ind][amt] != -1) return dp[ind][amt];

        // Don't take current coin
        int dontTake = Mem(coins, n, amt, ind - 1, dp);

        // Take current coin
        int take = INT_MAX;

        if (amt >= coins[ind]) {
            int temp = Mem(coins, n, amt - coins[ind], ind, dp);

            if (temp != INT_MAX)
                take = 1 + temp;
        }

        return dp[ind][amt] = min(take, dontTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        // int ans = Rec(coins, n, amount, n - 1);

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = Mem(coins, n, amount, n - 1, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};