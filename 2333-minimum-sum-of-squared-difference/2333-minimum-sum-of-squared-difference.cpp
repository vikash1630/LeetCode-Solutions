class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<int> d(n);
        long long total = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            d[i] = abs(nums1[i] - nums2[i]);
            total += d[i];
            mx = max(mx, d[i]);
        }
        if (total <= k) return 0;

        vector<long long> freq(mx + 1, 0);
        for (int x : d) freq[x]++;

        long long cnt = 0;                 // elements currently at level >= v
        for (int v = mx; v > 0 && k > 0; v--) {
            cnt += freq[v];
            if (cnt == 0) continue;
            if (k >= cnt) {
                k -= cnt;                  // lower whole top layer to v-1
                freq[v] = 0;
                if (k == 0) {              // they all end at v-1
                    freq[v - 1] += cnt;
                    break;
                }
            } else {
                freq[v] = cnt - k;         // these stay at v
                freq[v - 1] += k;          // k of them drop to v-1
                k = 0;
            }
        }

        long long ans = 0;
        for (long long v = 0; v <= mx; v++) ans += v * v * freq[v];
        return ans;
    }
};