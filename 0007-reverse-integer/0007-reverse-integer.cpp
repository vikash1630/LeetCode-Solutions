class Solution {
public:
    int reverse(int x) {
        x = 1LL*x;
        long long rem;
        long long rev = 0;
        bool flag = false;
        if (x < 0) {
            flag = true;
            x = 1LL*-1 * x;
        }
        while (x > 0) {
            rem = x % 10;
            rev = rev * 10 + rem;
            if (rev > INT_MAX) return 0;
            x = x/10;
        }
        if (flag) return -1 * rev;
        return rev;
    }
};