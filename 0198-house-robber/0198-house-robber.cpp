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
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // return rec(nums, n, 0);
        vector<int> dp(n, -1);
        return mem(nums, dp, n, 0);
    }
};