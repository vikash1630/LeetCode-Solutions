class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        int i = 0;
        while (i < n) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                char target;
                if (s[i] == ')')
                    target = '(';
                else if (s[i] == ']')
                    target = '[';
                else
                    target = '{';
                if (st.empty() || st.top() != target)
                    return false;

                st.pop();
            }
            i++;
        }
        if (st.size() == 0)
            return true;
        return false;
    }
};