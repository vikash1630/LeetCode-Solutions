class Solution {
    int solve(vector<int>& nums, int i, int j) {
        // Only one element left
        if (i == j)
            return nums[i];

        // Take the left element.
        // After taking it, the opponent becomes the "current player",
        // so subtract the opponent's best possible advantage.
        int takeLeft = nums[i] - solve(nums, i + 1, j);

        // Take the right element.
        int takeRight = nums[j] - solve(nums, i, j - 1);

        // Choose the move that gives the maximum advantage.
        return max(takeLeft, takeRight);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};