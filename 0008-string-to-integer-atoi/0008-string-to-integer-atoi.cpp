class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        int i = 0;

        // skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // sign check
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        long long ans = 0;

        // build number
        while (i < n && s[i] >= '0' && s[i] <= '9') {

            ans = ans * 10 + (s[i] - '0');

            // overflow handling
            if (sign * ans > INT_MAX) return INT_MAX;
            if (sign * ans < INT_MIN) return INT_MIN;

            i++;
        }

        return ans * sign;
    }
};