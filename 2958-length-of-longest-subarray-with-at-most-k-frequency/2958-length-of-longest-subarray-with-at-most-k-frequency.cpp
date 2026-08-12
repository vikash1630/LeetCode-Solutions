class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int left = 0;
        int right = 0;
        int ans = 0;
        while (left <= right && right < n) {
            freq[nums[right]]++;
            while (freq[nums[right]] > k && left < n) {
                freq[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};