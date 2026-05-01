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
            // Why ans += mpp[prefixSum - k] instead of ans++   => because we are counting possible number of sub arrays that means how many times the diffrence (prefixSum - k) appears that many more possible subarrays
            
            if (mpp.find(prefixSum - k) != mpp.end()) ans += mpp[prefixSum - k];
            mpp[prefixSum]++;
        }
        return ans;
    }
};