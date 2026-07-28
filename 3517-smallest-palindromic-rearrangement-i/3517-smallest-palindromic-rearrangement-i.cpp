class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string half = s.substr(0, n / 2);
        
        sort(half.begin(), half.end());
        
        string rev = half;
        reverse(rev.begin(), rev.end());
        
        if (n % 2 != 0) {
            return half + s[n / 2] + rev;
        }
        return half + rev;
    }
};