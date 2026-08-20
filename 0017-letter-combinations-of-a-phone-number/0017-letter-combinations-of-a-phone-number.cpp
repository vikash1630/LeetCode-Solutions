class Solution {
private:
    void solve(string &digits, vector<string> &phone, int ind, int n, string &str, vector<string> &ans) {
        if (ind == n) {
            ans.push_back(str);
            return;
        }
        for (char ch: phone[digits[ind] - '0']) {
            str += ch;
            solve(digits, phone, ind + 1, n, str, ans);
            str.pop_back();
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> phone = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        vector<string> ans;
        string str = "";
        solve(digits, phone, 0, n, str, ans);
        return ans;
    }
};