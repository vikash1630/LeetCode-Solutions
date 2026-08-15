class Solution {
private:
    int f(vector<int> &arr, int n, int k, int ind, vector<int> &dp) {
        if (ind == n) return 0;
        if (dp[ind] != -1) return dp[ind];
        int maxiEle = INT_MIN;
        int ans = INT_MIN;
        for (int i = ind;i<min(n, ind + k);i++) {
            maxiEle = max(maxiEle, arr[i]);
            int len = i - ind + 1;
            int sum = (len * maxiEle) + f(arr, n, k, i + 1, dp);
            ans = max(sum, ans);
        }
        return dp[ind] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(arr, n, k, 0, dp);
    }
};