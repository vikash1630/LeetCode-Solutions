class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        if (n == 0) return "";
        if (n == 1) return strs[0];
        string shortest = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].size() < shortest.size()) {
                shortest = strs[i];
            }
        }   
        int ind = 0;
        while (ind < shortest.size() && isPrefix(ind,strs,n)) {
            ans += strs[0][ind];
            ind++;
        }
        return ans;
    }

    bool isPrefix(int ind,vector<string>& strs,int n) {
        char ch = strs[0][ind];
        for (int i = 1;i<n;i++) {
            if (strs[i][ind] != ch) {
                return false;
            }
        }
        return true;
    }
};