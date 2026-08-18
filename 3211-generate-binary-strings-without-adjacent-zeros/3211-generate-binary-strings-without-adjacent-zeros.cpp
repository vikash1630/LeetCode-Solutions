class Solution {
private:
    void solve(int n, vector<string> &ans, int ind, string &str) {
        if (ind == n) {
            ans.push_back(str);
            return;
        }

        // put one
        str += "1";
        solve(n, ans, ind + 1, str);
        str.pop_back();

        // put zero
        int a = str.size();
        if (a < 1 || str[a - 1] == '1') {
            str += "0";
            solve(n, ans, ind + 1, str);
            str.pop_back();
        }
        return;
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string str = "";
        solve(n, ans, 0, str);
        return ans;
    }
};