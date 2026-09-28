class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0;
        int cnt = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                cnt++;
                ans = max(cnt, ans);
            }
            else if (s[i] == ')') {
                cnt--;
            }
            i++;
        }
        return ans;
    }
};