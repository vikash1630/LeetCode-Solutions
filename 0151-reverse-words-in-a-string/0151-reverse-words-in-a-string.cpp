class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int n = s.size();
        string dum = "";
        int startChar = 0;
        int EndChar = n - 1;
        for (int i = 0;i<n;i++) {
            if (s[i] != ' ') {
                startChar = i;
                break;
            }
        }
        for (int i = n - 1;i>=0;i--) {
            if (s[i] != ' ') {
                EndChar = i;
                break;
            }
        }
        for (int i = EndChar;i>=startChar;i--) {
            if (s[i] == ' ') {
                for (int j = dum.size() - 1;j>=0;j--) {
                    result += dum[j];
                }
                if (dum != "") result += ' ';
                dum = "";
            }
            else {
                dum += s[i];
            }
        }
        for (int j = dum.size() - 1;j>=0;j--) {
            result += dum[j];
        }
        return result;
    }
};