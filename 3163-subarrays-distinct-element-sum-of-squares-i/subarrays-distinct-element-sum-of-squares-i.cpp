class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0;i<n;i++) {
            unordered_set<int> st;
            for (int j = i;j<n;j++) {
                st.insert(nums[j]);
                ans += (st.size()) * (st.size()) % mod;
            }
        }
        return ans;
    }
};