class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,  int> mpp;
        for (int i = 0;i<word.size();i++) {
            mpp[word[i]]++;
        }
        vector<pair<char, int>> v;
        for (char ch = 'a';ch<='z';ch++) {
            if (mpp.find(ch) != mpp.end()) {
                v.push_back({ch, mpp[ch]});
            }
            else {
                v.push_back({ch, 0});
            }
        }
        sort(v.begin(), v.end(), [](const pair<char, int> &a, const pair<char, int> &b) {
        return a.second > b.second;
        });
        int i = 0;
        int ans = 0;
        for (auto &it: v) {
            char ch = it.first;
            int cnt = it.second;
            ans += cnt * ((i/8) + 1);
            i++;
        }
        return ans;
    }
};