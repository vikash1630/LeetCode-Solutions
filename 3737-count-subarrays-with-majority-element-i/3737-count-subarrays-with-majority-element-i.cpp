class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int count = 0;
        for (int i = 0;i<nums.size();i++) {
            for (int j = i;j<nums.size();j++) {
                mpp[nums[j]]++;
                if (mpp.find(target) != mpp.end()) {
                    if (mpp[target] > (j - i + 1)/2) count++;
                }
            }
            mpp.clear();
        }
        return count;
    }
};