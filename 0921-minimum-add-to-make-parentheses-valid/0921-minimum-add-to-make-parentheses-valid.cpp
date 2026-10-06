class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int n = s.size();
        stack<char> st;
        for (int i = 0;i<n;i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if (st.size() != 0 && st.top() == '(') {
                    st.pop();
                }
                else ans++;
            }
        }
        while (st.size() != 0) {
            ans++;
            st.pop();
        }
        return ans;
    }
};