class Solution {
public:
    bool isAnagram(string s, string t) {
        int m1[256] = {0};
        int m2[256] = {0};
        if (s.size() != t.size()) return false;
        for (int i = 0;i<s.size();i++) {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for (int i = 0;i<256;i++) {
            if (m1[i] != m2[i]) return false;
        }
        return true;
    }
};