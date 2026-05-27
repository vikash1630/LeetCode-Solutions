class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_map<char,int> lower;
        unordered_map<char,int> upper;
        for (int i = 0;i<n;i++) {
            if (word[i] < 'a') {
                if (upper.find(word[i]) == upper.end()) {
                    upper[word[i]] = i;
                }
            }
            else {
                lower[word[i]] = i;
            }
        }
        int ans = 0;
        for (auto it : upper) {
            char lowerChar = it.first + 32;
            if (lower.find(lowerChar) != lower.end() && lower[lowerChar] < it.second) ans++;
        }


        return ans;
    }
};