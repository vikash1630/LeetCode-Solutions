class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int ans = 0;
        int left = 0;
        int right = 0;

        unordered_map<char, int> freq;
        int maxFreq = 0;

        while (right < n) {

            // Expand
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);

            // Shrink until valid
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }

            // Current window is valid
            int len = right - left + 1;
            ans = max(ans, len);

            right++;
        }

        return ans;
    }
};