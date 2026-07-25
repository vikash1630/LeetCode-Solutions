class Solution {
public:
    int maxProduct(int n) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        while (n > 0) {
            int r = n % 10;
            if (max1 < r) {
                max2 = max1;
                max1 = r;
            }
            else if (max1 == r) max2 = r;
            else if (max1 > r && max2 < r) max2 = r;
            n = n/10;
        }
        if (max1 == INT_MIN || max2 == INT_MIN) return -1;
        return max1 * max2;
    }
};