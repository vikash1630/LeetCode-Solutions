class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxi = INT_MIN;
        // int sum = 0;
        // for (int i = 0;i<nums.size();i++) {
        //     mini = min(nums[i],mini);
        //     maxi = max(nums[i],maxi);
        //     sum += nums[i];
        // }
        // int ele = mini;
        unordered_map<int,int> mpp;
        for (int i = 0;i<nums.size();i++) {
            maxi = max(nums[i],maxi);
            mpp[nums[i]] = 1;
        }
        int i = 1;
        if (maxi <= 0) return 1;
        while (i < maxi) {
            if (mpp.find(i) == mpp.end()) return i;
            i++;
        }
        return maxi + 1;
    }
};