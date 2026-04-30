class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int posInd = 0;
        int negInd = 1;
        for (int i = 0;i<n;i++) {
            if (nums[i] < 0) {
                ans[negInd] = nums[i];
                negInd += 2;
            }
            else {
                ans[posInd] = nums[i];
                posInd += 2;
            }
        }

        return ans;


        // Brute Force
        // vector<int> pos;
        // vector<int> neg;
        // for (int i = 0;i<nums.size();i++)  {
        //     if (nums[i] < 0) {
        //         neg.push_back(nums[i]);
        //     }
        //     else {
        //         pos.push_back(nums[i]);
        //     }
        // }
        // int j = 0;
        // int k = 0;
        // for (int i = 0;i<nums.size();i++) {
        //     if (i%2 == 0) {
        //         nums[i] = pos[j];
        //         j++;
        //     }
        //     else {
        //         nums[i] = neg[k];
        //         k++;
        //     }
        // }
        // return nums;
    }
};