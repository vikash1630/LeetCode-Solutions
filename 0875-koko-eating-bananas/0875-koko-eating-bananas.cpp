class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;
        if (h == n) return high;
        int ans;
        while (low <= high) {
            int mid = low + (high - low)/2;
            double cnt = 0;
            for (int i = 0;i<n;i++) {
                // getting ceil value of piles[i]/mid using simple math
                cnt += (piles[i] + mid - 1) / mid;
            }
            if (cnt <= h) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;

        }
        return low;
    }
};