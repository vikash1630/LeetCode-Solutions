class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int j = 0;
        int count = 0;
        while (j < nums.size()) {
            if (nums[j] == 1) count++;
            else {
                ans = max(ans,count);
                count = 0;
                i = j + 1;
            }
            j++;
        }
        ans = max(ans,count);
        return ans;
    }
};