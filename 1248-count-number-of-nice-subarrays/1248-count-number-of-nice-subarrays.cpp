class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k - 1);
    }
    int solve(vector<int>& nums,int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int cnt = 0;
        int cntOdds = 0;
        while (right < n) {
            if (nums[right]%2 == 1) cntOdds++;
            while (left <= right && cntOdds > k) {
                if (nums[left]%2 == 1) cntOdds--;
                left++;
            }
            cnt = cnt + (right - left + 1);
            right++;
        }
        return cnt;
    }
};