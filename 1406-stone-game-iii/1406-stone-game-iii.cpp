class Solution {
private:
    int Rec(vector<int> &nums, int n, int ind) {
        if (ind == n) return 0;
        int one = nums[ind] - Rec(nums, n, ind + 1);
        int two = INT_MIN;
        int three = INT_MIN;
        if (ind + 1 < n) two = nums[ind] + nums[ind + 1] - Rec(nums, n, ind + 2);
        if (ind + 2 < n) three = nums[ind] + nums[ind + 1] + nums[ind + 2] - Rec(nums, n, ind + 3);
        return max(one, max(two, three));
    }

    int Mem(vector<int> &nums, int n, int ind, vector<int> &dp) {
        if (ind == n) return 0;
        if (dp[ind] != INT_MIN) return dp[ind];
        int one = nums[ind] - Mem(nums, n, ind + 1, dp);
        int two = INT_MIN;
        int three = INT_MIN;
        if (ind + 1 < n) two = nums[ind] + nums[ind + 1] - Mem(nums, n, ind + 2, dp);
        if (ind + 2 < n) three = nums[ind] + nums[ind + 1] + nums[ind + 2] - Mem(nums, n, ind + 3, dp);
        return dp[ind] = max(one, max(two, three));
    }

    int Tab(vector<int> &nums, int n) {
        vector<int> dp(n, INT_MIN);
        dp[n - 1] = nums[n - 1];
        if (n - 2 >= 0) dp[n - 2] = max(nums[n - 2] + nums[n - 1], nums[n - 2] - nums[n - 1]); 
        if (n - 3 >= 0) dp[n - 3] = max(nums[n - 3] + nums[n - 2] + nums[n - 1], nums[n - 3] + nums[n - 2] - nums[n - 1]);
        for (int i = n - 4;i>=0;i--) {
            int one = nums[i] - dp[i + 1];
            int two = INT_MIN;
            int three = INT_MIN;
            two = nums[i] + nums[i + 1] - dp[i + 2];
            three = nums[i] + nums[i + 1] + nums[i + 2] - dp[i + 3];
            dp[i] = max(one, max(two, three));
        }
        return dp[0];
    }

    
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // int score = Rec(stoneValue, n, 0);
        vector<int> dp(n, INT_MIN);
        // int score = Mem(stoneValue, n, 0, dp);
        int score = Tab(stoneValue, n);
        
        if (score > 0) return "Alice";
        else if (score < 0) return "Bob";
        return "Tie";
    }
};