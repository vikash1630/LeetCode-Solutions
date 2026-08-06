class Solution {
private:
    int product(int val) {
        int ans = 1;
        while (val > 0) {
            int rem = val%10;
            if (rem == 0) return 0;
            ans *= rem;
            val = val/10;
        }
        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        int val = n;
        int ch = product(val);
        if (ch%t == 0) return val;
        int i = 1;
        while (i<=9) {
            if (ch%t == 0) return val;
            int rem = val%10;
            ch = ch/rem;
            ch = ch * ((rem + 1) % 10);
            val++;
        }
        return n;
    }
};