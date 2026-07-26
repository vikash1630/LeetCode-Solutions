class Solution {
private:
    // Reccursion
    int rec(vector<int>& nums, int n, int ind) {
        if (ind >= n) return 0;

        // Take current => cant take ind + 1
        int take = rec(nums, n, ind + 2) + nums[ind];

        // Dont Take current => can take ind + 1
        int dontTake = rec(nums, n, ind + 1);

        return max(take, dontTake);
    }

    // Memoization
    int mem(vector<int> &nums, vector<int> &dp, int n, int ind) {
        if (ind >= n) return 0;
        if (dp[ind] != -1) return dp[ind];
        int take = mem(nums, dp, n, ind + 2) + nums[ind];
        int dontTake = mem(nums, dp, n, ind + 1); 
        return dp[ind] = max(take, dontTake);
    }

    // Tabulation
    int tab(vector<int>& nums, int n) {
    vector<int> dp(n + 2, 0);

    for (int i = n - 1; i >= 0; i--) {
        int take = nums[i] + dp[i + 2];
        int dontTake = dp[i + 1];

        dp[i] = max(take, dontTake);
    }

    return dp[0];
    }

    int sp(vector<int> &nums, int n) {
        int prev1 = 0;
        int prev2 = 0;
        for (int i = n - 1;i>=0;i--) {
            int take = nums[i] + prev2;
            int dontTake = prev1;
            int cur = max(take, dontTake);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return rec(nums, n, 0);
        vector<int> dp(n, -1);
        // return mem(nums, dp, n, 0);
        // return tab(nums, n);
        return sp(nums, n);
    }
};