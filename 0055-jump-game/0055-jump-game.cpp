class Solution {
private:
    bool solve(vector<int> &nums, int ind, int n, vector<int> &dp) {
        if (ind >= n - 1) return true;
        if (nums[ind] == 0) return false;
        if (dp[ind] != -1) return dp[ind];
        for (int i = (ind + nums[ind]) ;i>ind;i--) {
            bool flag = solve(nums, i, n, dp);
            if (flag == true) return dp[ind] = true;
        }
        return dp[ind] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, 0, n, dp);
    }
};