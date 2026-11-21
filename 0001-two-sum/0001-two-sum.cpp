class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0;i<n;i++) {
            int sum = nums[i];
            if (mpp.find(target - sum) != mpp.end()) return {mpp[target - sum], i};

            mpp[sum] = i;
        }
        return {};
    }
};