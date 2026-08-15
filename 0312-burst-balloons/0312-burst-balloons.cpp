class Solution {
private:
    int f(vector<int> &nums, int i, int j) {
        if (i > j) return 0;
        int maxi = INT_MIN;
        for (int ind = i;ind<=j;ind++) {
            int sum = nums[i - 1] * nums[ind] * nums[j + 1] + f(nums, i, ind - 1) + f(nums, ind + 1, j);
            maxi = max(maxi, sum);
        }
        return maxi;
    }

    int f(vector<int> &nums, int i, int j, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for (int ind = i;ind<=j;ind++) {
            int sum = nums[i - 1] * nums[ind] * nums[j + 1] + f(nums, i, ind - 1, dp) + f(nums, ind + 1, j, dp);
            maxi = max(maxi, sum);
        }
        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(nums, 1, n - 2, dp);
    }
};