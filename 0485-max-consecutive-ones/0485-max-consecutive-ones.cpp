class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        int count = 0;
        while (right < n) {
            while (left < right && nums[left] == 0) left++;
            if (nums[right] == 1) {
                count++;
                ans = max(ans, count);
            }
            else {
                left = right;
                count = 0;
            }
            right++;
        }
        return ans;
    }
};