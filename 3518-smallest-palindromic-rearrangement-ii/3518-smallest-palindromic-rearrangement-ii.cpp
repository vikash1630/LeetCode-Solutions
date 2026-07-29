class Solution {
private:
    // Cap counting to prevent integer overflow since k fits within standard bounds
    static const long long LIMIT = 1000001;

    // Helper function to calculate multinomial permutations: total! / (c1! * c2! * ... * c26!)
    long long countWays(const vector<int>& counts, int total_len) {
        long long res = 1;
        int current_len = 0;

        for (int c : counts) {
            if (c == 0) continue;
            for (int i = 1; i <= c; ++i) {
                current_len++;
                res = res * current_len / i;
                if (res > LIMIT) res = LIMIT;
            }
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half_freq(26, 0);
        int half_len = 0;
        char mid = 0;

        // Step 1: Collect half frequencies and determine middle character if s is odd-length
        for (int i = 0; i < 26; ++i) {
            half_freq[i] = freq[i] / 2;
            half_len += half_freq[i];
            if (freq[i] % 2 == 1) {
                mid = 'a' + i;
            }
        }

        // Step 2: Check if fewer than k total palindromic permutations exist
        if (countWays(half_freq, half_len) < k) return "";

        string left = "";
        int remaining_len = half_len;

        // Step 3: Digit-by-digit construction of the left half
        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_freq[c] == 0) continue;

                half_freq[c]--;
                long long ways = countWays(half_freq, remaining_len - 1);

                if (ways >= k) {
                    left += (char)('a' + c);
                    remaining_len--;
                    break;
                } else {
                    k -= ways;
                    half_freq[c]++; // backtrack
                }
            }
        }

        // Step 4: Mirror the left half to build the complete palindrome
        string right = left;
        reverse(right.begin(), right.end());

        if (mid != 0) {
            return left + mid + right;
        }
        return left + right;
    }
};