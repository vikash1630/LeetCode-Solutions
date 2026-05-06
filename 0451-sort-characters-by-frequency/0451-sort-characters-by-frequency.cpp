class Solution {
public:
    string frequencySort(string s) {
        pair<int, char> freq[256];
        for (int i = 0;i<256;i++) {
            freq[i] = {0,(char)i};
        }
        for (int i = 0;i<s.size();i++) {
            freq[s[i]].first++;
        }
        sort(freq,freq + 256, [](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first > b.first;
        });
        string ans = "";
        for (int i = 0;i<256;i++) {
            if (freq[i].first > 0) {
                while(freq[i].first > 0) {
                    ans += freq[i].second;
                    freq[i].first--;
                } 
            }
        }
        return ans;
    }
};