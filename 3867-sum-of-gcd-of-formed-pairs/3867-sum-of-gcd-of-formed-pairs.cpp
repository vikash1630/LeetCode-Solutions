class Solution {
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];

        vector<int> prefixGcd(n);
        prefixGcd[0] = maxi;
        for (int i = 1;i<n;i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(maxi, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long sum = 0;
        for (int i = 0;i<n/2;i++) {
            if (i == n - 1 - i) break;
            sum += 1LL*gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        }
        return sum;
    }
};