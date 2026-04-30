class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int i;
        for (i = 0;i<n;i++) {
            mpp[nums[i]]++;
        }
        int k;
        if (n%2 == 1) k = n/2 + 1;
        else k = n/2;
        for (auto it: mpp) {
            if (it.second >= k) return it.first;
        }
        return -1;
    }
};