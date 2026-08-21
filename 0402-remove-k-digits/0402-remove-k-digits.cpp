class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k == n) {
            return "0";
        }
        stack<char> st;
        int i = 0;
        while (i<n) {
            if (st.empty()) {
                st.push(num[i]);
            }
            else {
                while(!st.empty() && st.top() > num[i] && k>0) {
                    k--;
                    st.pop();
                }
                if (k == 0) {
                    while (i<n) {
                        st.push(num[i]);
                        i++;
                    }
                }
                else {
                    st.push(num[i]);
                }
            }
            i++;
        }
        if (k != 0) {
            while (k) {
                st.pop();
                k--;
            }
        }
        vector<char> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        string res(ans.begin(),ans.end());
        for (i = 0; i < res.size(); i++) {
            if (res[i] != '0') {
                break;
            }
        }   
        res = (i == res.size()) ? "0" : res.substr(i);
        return res;
    }
};