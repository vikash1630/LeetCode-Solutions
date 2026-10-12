
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(32, 0);
        long long mod = 1e9 + 7;

        // Count occurrences of each set bit
        for (int num : nums) {
            for (int b = 0; b < 32; b++) {
                if (num & (1LL << b)) {
                    bits[b]++;
                }
            }
        }

        long long ans = 0;

        // Construct k numbers with as many available bits as possible
        for (int i = 0; i < k; i++) {
            long long num = 0;

            for (int b = 0; b < 32; b++) {
                if (bits[b] > 0) {
                    num |= (1LL << b);
                    bits[b]--;
                }
            }

            ans = (ans + num * num) % mod;
        }

        return ans;
    }
};
