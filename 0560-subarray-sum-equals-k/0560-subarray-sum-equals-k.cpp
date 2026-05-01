class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int prefixSum = 0;
        int ans = 0;
        for (int i = 0;i<n;i++) {
            prefixSum += nums[i];
            if (k == prefixSum) ans++;
            if (mpp.find(prefixSum - k) != mpp.end()) ans += mpp[prefixSum - k];
            mpp[prefixSum]++;
        }
        return ans;
    }
};