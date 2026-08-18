class Solution {
private:
    vector<int> Rec(int ind, int prevInd, vector<int>& nums,
                    int n, vector<vector<vector<int>>>& dp) {

        if (ind == n)
            return {};

        // Already calculated
        if (!dp[ind][prevInd + 1].empty())
            return dp[ind][prevInd + 1];

        // Don't take
        vector<int> notTake = Rec(ind + 1, prevInd, nums, n, dp);

        // Take
        vector<int> take;

        if (prevInd == -1 || nums[ind] % nums[prevInd] == 0) {
            take = Rec(ind + 1, ind, nums, n, dp);

            // Add current element
            take.insert(take.begin(), nums[ind]);
        }

        // Store the better answer
        if (take.size() > notTake.size())
            return dp[ind][prevInd + 1] = take;

        return dp[ind][prevInd + 1] = notTake;
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        // dp[ind][prevInd + 1]
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n + 1)
        );

        return Rec(0, -1, nums, n, dp);
    }
};