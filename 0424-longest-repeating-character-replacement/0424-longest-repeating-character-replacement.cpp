class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> mpp;
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int maxfreq = 0;
        int n = s.size();
        while (right < n) {
            mpp[s[right] - 'A']++;
            maxfreq = max(maxfreq,mpp[s[right] - 'A']);
            while ((right - left + 1) - maxfreq > k) {
                mpp[s[left] - 'A']--;
                maxfreq = 0;
                for (int i = 0;i<26;i++) {
                    maxfreq = max(maxfreq,mpp[i]);
                }
                left++;
            }
            if ((right - left + 1) - maxfreq <= k) {
                maxLen = max(maxLen,(right - left + 1));
            }
            right++;
        }
        return maxLen;
    }
};