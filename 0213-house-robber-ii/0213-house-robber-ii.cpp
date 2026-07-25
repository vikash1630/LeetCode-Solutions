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

    // Tabulation
    int tab(vector<int>& nums, int n) {
        vector<int> dp(n + 2, 0);

        // Ignore first
        for (int i = n - 1;i>0;i--) {
            // Take
            int take = dp[i + 2] + nums[i];

            // Dont Take
            int dontTake = dp[i + 1];

            dp[i] = max(take, dontTake);

        }

        // Ignore last
        vector<int> dp1(n + 2, 0);
        for (int i = n - 2;i>=0;i--) {
            // Take
            int take = dp1[i + 2] + nums[i];
            
            // Dont Take
            int dontTake = dp1[i + 1];

            dp1[i] = max(take, dontTake);
        }

        return max(dp[1], dp1[0]);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        // return rec(nums, n, 0);
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        // int a = memIgnoreOne(nums, n, 1, dp1);
        // int b = memIgnorelast(nums, n, 0, dp2);
        // return max(a, b);
        return tab(nums, n);
    }
};