class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for (int i = 0;i<n;i++) {
            if (nums[i] != 0) {
                swap(nums[i],nums[j]);
                j++;
            }
        }


        // Brute Force
        // int cnt = 0;
        // int n = nums.size();
        // int i = 0;
        // while (i<n) {
        //     if (nums[i] == 0) {
        //         cnt++;
        //     }
        //     i++;
        // }
        // int j = 0;
        // i = 0;
        // while (i<n) {
        //     if (j == n - cnt) break;
        //     if (nums[i] != 0) {
        //         nums[j] = nums[i];
        //         j++;
        //     }
        //     i++;
        // }
        // while (j<n) {
        //     nums[j] = 0;
        //     j++;
        // } 
    }
};