class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int cnt = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue; 
            }
            else if (nums[i] == nums[i - 1] + 1) {
                cnt++;
            }
            else {
                longest = max(longest, cnt);
                cnt = 1;
            }
        }

        return max(longest, cnt);
    }
};