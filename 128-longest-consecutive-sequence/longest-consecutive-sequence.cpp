class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> st;

        for (auto it : nums) st.insert(it);

        int ans = 0;
        int cnt = 0;
        int prev = INT_MIN;

        while (st.size() != 0) {
            int ele = *st.begin();

            if (prev != INT_MIN && prev + 1 == ele)
                cnt++;
            else
                cnt = 1;

            ans = max(ans, cnt);
            prev = ele;
            st.erase(st.begin());
        }

        return ans;
    }
};