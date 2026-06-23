class Solution {
private:
    int solve(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int> mpp;
        int count = 0;
        while (j < n) {
            mpp[nums[j]]++;
            while (mpp.size() > k) {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if (k == 0) return 0;
        return solve(nums,k) - solve(nums,k - 1);
    }
};