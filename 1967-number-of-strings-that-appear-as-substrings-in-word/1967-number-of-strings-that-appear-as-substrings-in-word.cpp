class Solution {
private:
    bool solve(string &a,string b,int n) {
        for (int i = 0;i<n;i++) {
            if (b[i] == a[0]) {
                if (i + a.size() > n) return false;
                string c = "";
                for (int j = i;j<i + a.size();j++) {
                    c += b[j];
                }
                if (c == a) return true;
            }
        }
        return false;
    }

public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();
        int count = 0;
        for (int i = 0;i<patterns.size();i++) {
            string a = patterns[i];
            bool flag = solve(a,word,n);
            if (flag) count++;
        }
        return count;
    }
};