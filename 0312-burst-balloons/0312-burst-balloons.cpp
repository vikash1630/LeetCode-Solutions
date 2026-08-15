class Solution {
private:
    int f(vector<int>& nums, int i, int j) {
        if (i > j)
            return 0;
        int maxi = INT_MIN;
        for (int ind = i; ind <= j; ind++) {
            int sum = nums[i - 1] * nums[ind] * nums[j + 1] +
                      f(nums, i, ind - 1) + f(nums, ind + 1, j);
            maxi = max(maxi, sum);
        }
        return maxi;
    }

    int f(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxi = INT_MIN;
        for (int ind = i; ind <= j; ind++) {
            int sum = nums[i - 1] * nums[ind] * nums[j + 1] +
                      f(nums, i, ind - 1, dp) + f(nums, ind + 1, j, dp);
            maxi = max(maxi, sum);
        }
        return dp[i][j] = maxi;
    }

    int f(vector<int>& nums, int n) {
        int dp[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = n - 2; i >= 1; i--) {
            for (int j = i; j < n - 1; j++) {
                int maxi = INT_MIN;
                for (int ind = i; ind <= j; ind++) {
                    int sum = nums[i - 1] * nums[ind] * nums[j + 1] +
                              dp[i][ind - 1] + dp[ind + 1][j];
                    maxi = max(maxi, sum);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n - 2];
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f(nums, 1, n - 2, dp);
        return f(nums, n);
    }
};