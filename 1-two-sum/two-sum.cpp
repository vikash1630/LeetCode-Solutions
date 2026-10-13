class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mpp;
        int n = nums.size();
        for (int i = 0;i<n;i++) {
            int sum = nums[i];
            if (mpp.find(target - sum) != mpp.end()) return {mpp[target-sum],i};
            mpp[sum] = i;
        }
        return {-1,-1};
        
        //  Brute Force
        // vector<int> temp = nums;
        // int left = 0;
        // int n = nums.size();
        // int right = n - 1;
        // sort(temp.begin(),temp.end());
        // while (left < right) {
        //     int sum = temp[left] + temp[right];
        //     if (sum == target) break;
        //     if (sum < target) left++;
        //     else right--;
        // }

        // int a = -1;
        // int b = -1;
        // for (int i = 0;i<n;i++) {
        //     if (nums[i] == temp[left] || nums[i] == temp[right]) {
        //         if (a == -1) {
        //             a = i;
        //             continue;
        //         }
        //         b = i;
        //         break;
        //     }
        // }

        // return {a,b};
    }
};