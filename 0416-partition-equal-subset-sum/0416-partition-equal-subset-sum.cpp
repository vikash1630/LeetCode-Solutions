class Solution {
private:
    bool Rec(vector<int> &nums, int n, int total, int sum, int ind) {
        if (total - sum == sum) return true;
        if (ind == n) return false;

        sum += nums[ind];
        bool take = Rec(nums, n, total, sum, ind + 1);

        sum -= nums[ind];
        bool dontTake = Rec(nums, n, total, sum, ind + 1);

        return take || dontTake;
    }

    bool Mem(vector<int> &nums, vector<vector<int>> &dp, int ind, int target) {
        if (target == 0) return dp[ind][target] = 1;
        if (ind == 0) {
            if (target == nums[ind]) return dp[ind][target] = 1;
            return dp[ind][target] = 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        // Dont Take
        bool dontTake = Mem(nums, dp, ind - 1, target);

        // Take
        bool take = false;
        if (target >= nums[ind]) take = Mem(nums, dp, ind - 1, target - nums[ind]);

        return dp[ind][target] = take || dontTake;
    }

    bool Tab(vector<int> &nums, int n, int target) {
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0;i<n;i++) dp[i][0] = 1;
        if (nums[0] <= target) dp[0][nums[0]] = 1;

        for (int i = 1;i<n;i++) {
            for (int j = 0;j<=target;j++) {
                // dont take
                bool dontTake = dp[i - 1][j];
                // Take
                bool take = 0;
                if (j >= nums[i]) take = dp[i - 1][j - nums[i]];

                dp[i][j] = take || dontTake;
            }
        }
        
        return dp[n - 1][target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for (int i = 0;i<n;i++) {
            target += nums[i];
        }
        int sum = 0;
        if (target % 2 != 0) return false;
        target = target/2;
        // vector<vector<int>> dp(n, vector<int>(target + 1, -1)); 
        // return Mem(nums, dp, n - 1, target);
        // return Rec(nums, n, target, sum, 0);
        return Tab(nums, n, target);
    }
};