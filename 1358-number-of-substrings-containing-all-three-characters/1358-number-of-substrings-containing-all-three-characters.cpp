class Solution {
public:
    int numberOfSubstrings(string s) {
        int occOfa = 0;
        int occOfb = 0;
        int occOfc = 0;
        int n = s.size();
        int ans = 0;
        int left = 0;
        int right = 0;
        while (right < n) {
            if (s[right] == 'a') occOfa = 1;
            if (s[right] == 'b') occOfb = 1;
            if (s[right] == 'c') occOfc = 1;
            
            if ((occOfa == 1 && occOfb == 1 && occOfc == 1)) {
                ans += n - right;
                left++;
                right = left;
                occOfa = 0;
                occOfb = 0;
                occOfc = 0;
                continue;
            }
            right++;
        }
        return ans;
    }
};