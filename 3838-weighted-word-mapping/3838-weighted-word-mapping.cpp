class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (int i = 0;i<words.size();i++) {
            string word = words[i];
            int sum = 0;
            for (auto &it: word) {
                sum += weights[it - 'a'];
            }
            sum = sum % 26;
            sum = 26 - sum - 1;
            ans += char(sum + 'a');
        }
        return ans;
    }
};