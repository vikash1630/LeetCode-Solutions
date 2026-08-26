class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();

        string ans = "";
        int small_len = INT_MAX;

        int cntOne = 0;
        int left = 0;
        int right = 0;

        while (right < n) {

            if (s[right] == '1')
                cntOne++;

            // Too many 1s
            while (cntOne > k) {

                if (s[left] == '1')
                    cntOne--;

                left++;
            }

            // Remove unnecessary leading zeros
            while (left <= right && s[left] == '0') {
                left++;
            }

            if (cntOne == k) {

                string a = s.substr(left, right - left + 1);
                int len = right - left + 1;

                if (len < small_len) {
                    small_len = len;
                    ans = a;
                }
                else if (len == small_len && ans > a) {
                    ans = a;
                }
            }

            right++;
        }

        return ans;
    }
};