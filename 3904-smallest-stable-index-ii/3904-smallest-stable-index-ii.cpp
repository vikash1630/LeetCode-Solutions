class Solution {
private:
    int findMinInd(vector<int> &nums, int n, int ind) {
        int mini = nums[ind];
        int ans = ind;
        for (int i = n - 1;i>=ind;i--) {
            if (mini > nums[i]) {
                mini = nums[i];
                ans = i;
            }
        } 
        return ans;
    }
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = nums[0];
        int minInd = -1;
        for (int i = 0;i<n;i++) {
            maxi = max(maxi, nums[i]);
            if (minInd == -1 || minInd < i) {
                minInd = findMinInd(nums, n, i);
            }
            int ch = maxi - nums[minInd];
            if (ch <= k) return i;
        }
        return -1;
    }
};