class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        int maxi = nums[i];
        int ind = i;
        i--;
        while (i >= 0) {
            if (nums[i] < maxi) {
                break;
            }
            if (maxi < nums[i]) {
                maxi = nums[i];
                ind = i;
            }
            i--;
        }
        if (i == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        int nextSmall = maxi;
        
        int j = i;
        for (j = i + 1;j<n;j++) {
            if (nums[j] > nums[i]) {
                if (nextSmall > nums[j] && nums[j] > nums[i]) {
                    ind = j;
                    nextSmall = nums[j];
                }
            }
        }
        swap(nums[i], nums[ind]);
        sort(nums.begin() + i + 1, nums.end());
    }
};