class Solution {
private:
    int findMin(vector<int> &nums, int ind, int n) {
        int mini = nums[ind];
        for (int i = ind;i < n;i++) mini = min(mini, nums[i]);
        return mini;
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = nums[0];
        
        for (int i = 0;i<n;i++) {
            maxi = max(maxi, nums[i]);
            int mini = findMin(nums, i, n);
            if (maxi - mini <= k) {
                return i;
            }
        }
        
        return -1;
    }
};