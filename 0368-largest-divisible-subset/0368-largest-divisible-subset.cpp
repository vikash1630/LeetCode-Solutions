class Solution {
private:
    int Rec(vector<int>& nums, int i, int prev,
            vector<vector<int>>& dp) {

        if (i == nums.size())
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        // Not take
        int notTake = Rec(nums, i + 1, prev, dp);

        // Take
        int take = 0;

        if (prev == -1 || nums[i] % nums[prev] == 0)
            take = 1 + Rec(nums, i + 1, i, dp);

        return dp[i][prev + 1] = max(take, notTake);
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        Rec(nums, 0, -1, dp);

        // Reconstruct answer
        vector<int> ans;
        int i = 0, prev = -1;

        while (i < n) {

            int notTake = Rec(nums, i + 1, prev, dp);

            int take = -1;

            if (prev == -1 || nums[i] % nums[prev] == 0)
                take = 1 + Rec(nums, i + 1, i, dp);

            if (take >= notTake) {
                ans.push_back(nums[i]);
                prev = i;
            }

            i++;
        }

        return ans;
    }
};