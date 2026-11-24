class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0)
            return abs(a);
        return gcd(b, a % b);
    }

    long long lcm(int a, int b) {
        if (a == 0 || b == 0)
            return 0;
        return abs((1LL * a / gcd(a, b)) * b);
    }

public:
    int maxLength(vector<int>& nums) {
        long long mod = 1e9 + 7;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long g = 0;
            long long l = 1;
            long long p = 1;
            for (int j = i; j < n; j++) {
                p = 1LL * p * nums[j] % mod;
                g = gcd(nums[j], g);
                l = lcm(nums[j], l);
                if (p == l * g)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};