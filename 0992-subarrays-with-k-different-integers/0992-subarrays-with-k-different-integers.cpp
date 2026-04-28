class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k - 1);
    }
    
    int solve(vector<int>& nums, int k) {
        if (k <= 0) return 0;
        int left = 0;
        int n = nums.size();
        int right = 0;
        int cnt = 0;
        unordered_map<int,int> mpp;
        while (right < n) {
            mpp[nums[right]]++;
            while (left < right && mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]);
                }
                left++;
            }
            cnt = cnt + (right - left + 1);
            right++;
        }
        return cnt;
    }

};