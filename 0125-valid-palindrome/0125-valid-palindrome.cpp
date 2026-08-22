class Solution {
private:
    bool palindrome(string &s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        string ans = "";
        for (int i = 0;i<s.size();i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') ans += (s[i] - 'A' + 'a');
            else if (s[i] >= 'a' && s[i] <= 'z') ans += s[i];
            else if (s[i] >= '0' && s[i] <= '9') ans += s[i];
        }
        return palindrome(ans);
    }
};