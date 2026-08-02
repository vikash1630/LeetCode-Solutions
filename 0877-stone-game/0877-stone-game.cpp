class Solution {
private:
    int Rec(vector<int> &piles, int left, int right) {
        if (left == right) return piles[left];


        int takeL = piles[left] - Rec(piles, left + 1, right);

        int takeR = piles[right] - Rec(piles, left, right - 1);

        return max(takeL, takeR);

    }

    int Mem(vector<int> &piles, int left, int right, vector<vector<int>> &dp) {
        if (left == right) return dp[left][right] = piles[left];

        if (dp[left][right] != INT_MIN) return dp[left][right];

        int takeL = piles[left] - Mem(piles, left + 1, right, dp);

        int takeR = piles[right] - Mem(piles, left, right - 1, dp);

        return dp[left][right] = max(takeL, takeR);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // if (Rec(piles, 0, n - 1) < 0) return false;
        // return true;
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return Mem(piles, 0, n - 1, dp);
    }
};