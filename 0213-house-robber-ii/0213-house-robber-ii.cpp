class Solution {
public:
    bool flag = false;
private:
    // Recursive
    int rec(vector<int> &nums, int n, int ind) {
        if (ind >= n) return 0;

        // Take
        int take = INT_MIN;
        if (ind == 0) flag = true;
        if (!flag || ind != n - 1) take = nums[ind] + rec(nums, n, ind + 2);

        if (ind == 0) flag = false;
        int dontTake = rec(nums, n, ind + 1);

        return max(take, dontTake);
    }

    // Memoization
    int memIgnoreOne(vector<int> &nums, int n, int ind, vector<int> &dp) {
        if (ind >= n) return 0;

        if (dp[ind] != -1) return dp[ind];
        // Take
        int take = nums[ind] + memIgnoreOne(nums, n, ind + 2, dp);

        // dont Take
        int dontTake = memIgnoreOne(nums, n, ind + 1, dp);

        return dp[ind] = max(take, dontTake);
    }

    int memIgnorelast(vector<int> &nums, int n, int ind, vector<int> &dp) {
        if (ind >= n - 1) return 0;

        if (dp[ind] != -1) return dp[ind];
        // Take
        int take = nums[ind] + memIgnorelast(nums, n, ind + 2, dp);

        // dont Take
        int dontTake = memIgnorelast(nums, n, ind + 1, dp);

        return dp[ind] = max(take, dontTake);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        // return rec(nums, n, 0);
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int a = memIgnoreOne(nums, n, 1, dp1);
        int b = memIgnorelast(nums, n, 0, dp2);
        return max(a, b);
    }
};