class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        for (auto ele : st) {
            if (st.find(ele - 1) == st.end()) {
                int cnt = 1;
                int curr = ele;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    cnt++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};