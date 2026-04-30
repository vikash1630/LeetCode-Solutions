class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // XOR as XOR cancels duplicates
        // a ^ a = 0 and 0 ^ a = a so pairs get cancelled and single number stays back

        int ans = 0;
        for (int i = 0;i<nums.size();i++) {
            ans = ans ^ nums[i];
        }
        return ans;
        
        // Brute Force
        // sort(nums.begin(),nums.end());
        // int i = 1;
        // int n = nums.size();
        
        // int temp = nums[0];
        // while(i<n) {
        //     if (nums[i] != temp) {
        //         return temp;
        //     }
        //     temp = nums[i + 1];
        //     i = i + 2;
        // }
        // return temp;
    }
};