class Solution {
private:
    int solve(vector<int> &nums, int i, int n) {
        int ind = -1;
        int ans = INT_MAX;
        for (int j = i + 1;j<n;j++) {
            if (nums[j] > nums[i] && ans > nums[j]) {
                ans = nums[j];
                ind = j;
            } 
        }
        return ind;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        
        for (i = n - 2;i>=0;i--) {
            if (nums[i] < nums[i + 1]) break;
        }
        if (i == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        // Find the element just > than nums[i] to replace
        int ind = solve(nums, i, n);
        int temp = nums[i];
        nums[i] = nums[ind];
        nums[ind] = temp;
        sort(nums.begin() + i + 1, nums.end());
    }
};