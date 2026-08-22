class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int m = n;
        while (n > 0) {
            int r = n % 10;
            prod = prod * r;
            sum = sum + r;
            n = n /10;
        }
        sum += prod;
        if (m % sum == 0) return true;
        return false;
    }
};