class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        long long N = n;
        double ans = x;
        long long i = 1;
        while (i<abs(N)) {
            ans = ans * ans;
            i = i * 2;
        }
        while (i != abs(N)) {
            ans = ans/x;
            i--;
        }
        if (N < 0) return 1/ans;
        return ans;
    }
};