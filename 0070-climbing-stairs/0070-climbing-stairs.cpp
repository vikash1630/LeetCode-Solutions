class Solution {
private:
// Recurrsion 
    int RecClimbStairs(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        // climb one stairs options + climb two stairs options
        return RecClimbStairs(n - 1) + RecClimbStairs(n - 2);
    }

// Memoization
    int MemClimbStairs(int n, vector<int> &dp) {
        if (n == 0) return dp[0] = 1;
        if (n == 1) return dp[1] = 1;
        // If already computed then dont recompute
        if (dp[n] != -1) return dp[n];
        return dp[n] = MemClimbStairs(n - 1, dp) + MemClimbStairs(n - 2, dp);
    }

// Tabulation
    int TabClimbStairs(int n, vector<int> &dp) {
        if (n == 1) return 1;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2;i<=n;i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }


public:
    int climbStairs(int n) {
        // return RecClimbStairs(n);
        // n + 1 since 0 is also there and n also counted
        vector<int> dp(n + 1, -1);
        // return MemClimbStairs(n, dp);
        return TabClimbStairs(n, dp);
    }
};