class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        for (auto &it: text) {
            mpp[it]++;
        }
        int count = INT_MAX;
        string s = "balon";
        for (auto &it: s) {
            if (mpp.find(it) == mpp.end()) return 0;
            if (it == 'l') continue;
            if (it == 'o') continue;
            count = min(count,mpp[it]);
        }
        count = min(count,(mpp['l']/2));
        count = min(count,(mpp['o']/2));
        return count;
    }
};