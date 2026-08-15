class Solution {
    // Cache max element in range [i...j] for O(1) lookups
    map<pair<int, int>, int> maxVal;

    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        // Base case: single leaf node costs 0
        if (i == j) return 0;

        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];

        int minCost = INT_MAX;

        // Try every partition point k from i to j - 1
        for (int k = i; k < j; k++) {
            int leftCost = solve(i, k, arr, dp);
            int rightCost = solve(k + 1, j, arr, dp);
            
            int rootValue = maxVal[{i, k}] * maxVal[{k + 1, j}];

            int totalCost = leftCost + rightCost + rootValue;
            minCost = min(minCost, totalCost);
        }

        return dp[i][j] = minCost;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        // Precompute maximum value for all ranges [i...j]
        for (int i = 0; i < n; i++) {
            maxVal[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxVal[{i, j}] = max(maxVal[{i, j - 1}], arr[j]);
            }
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, arr, dp);
    }
};