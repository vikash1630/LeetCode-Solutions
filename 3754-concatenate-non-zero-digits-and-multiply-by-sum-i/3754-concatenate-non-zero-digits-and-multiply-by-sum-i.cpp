class Solution {
private:
    int reverseNum(int x) {
        int y = 0;
        while (x > 0) {
            int r = x % 10;
            x = x /10;
            y = y * 10 + r;
        }
        return y;
    }
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        int x = 0;
        while (n > 0) {
            int r = n % 10;
            n = n/10;
            sum += r;
            if (r != 0) x = x * 10 + r;
        }
        x = reverseNum(x);
        return 1LL*sum * x;
    }
};