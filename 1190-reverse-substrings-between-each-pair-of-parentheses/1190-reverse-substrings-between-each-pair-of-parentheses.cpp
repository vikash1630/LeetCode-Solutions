class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                string str = "";
                while (st.size() != 0 && st.top() != '(') {
                    str += st.top();
                    st.pop();
                }
                // Pop '('
                st.pop();
                for (auto& it : str)
                    st.push(it);
            } else
                st.push(s[i]);
        }
        string str = "";
        while (st.size() != 0 && st.top() != '(') {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};