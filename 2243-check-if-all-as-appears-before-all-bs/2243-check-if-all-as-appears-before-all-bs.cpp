class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        bool b = false;
        for (int i = 0;i<n;i++) {
            if (s[i] == 'a' && b) return false;
            if (s[i] == 'b') b = true;
        }
        return true;
    }
};