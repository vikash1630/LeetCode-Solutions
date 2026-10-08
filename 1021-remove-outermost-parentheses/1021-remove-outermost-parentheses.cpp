class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        queue<char> q;
        int n = s.size();
        int cnt = 0;
        for (int i = 0;i<n;i++) {
            if (s[i] == '(') {
                q.push(s[i]);
                cnt++;
            }
            else {
                cnt--;
                q.push(s[i]);
            }
            if (cnt == 0) {
                q.pop();
                while (q.size() > 1) {
                    ans += q.front();
                    q.pop();
                }
                q.pop();
            }
        }
        return ans;
    }
};