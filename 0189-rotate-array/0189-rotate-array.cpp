class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k%n;
        int left = 0;
        int right = n - 1;
        while (left<=right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
        left = 0;
        right = k - 1;
        while (left<=right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
        left = k;
        right = n - 1;
        while (left<=right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }



        // Brute Force
        // int n = nums.size();
        // k = k%n;
        // int i = n - k;
        // vector<int> ans(n);
        // while (i<n) {
        //     ans[i - (n-k)] = nums[i];
        //     i++;
        // }
        // int j = i - (n-k);
        // i = 0;
        // while (i<n-k) {
        //     ans[j] = nums[i];
        //     i++;
        //     j++;
        // }
        // nums = ans;
        
    }

};