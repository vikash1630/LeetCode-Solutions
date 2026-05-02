class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        // Optimal Aproach - 1
        int ans = INT_MIN;
        int prod = 1;
        // Left To Right
        for (int i = 0;i<n;i++) {
            prod *= nums[i];
            if (prod > ans) ans = prod;
            if (prod == 0) {
                prod = 1;
            }
        }
        int ans2 = INT_MIN;
        prod = 1;
        for (int i = n - 1;i>=0;i--) {
            prod *= nums[i];
            if (prod > ans2) ans2 = prod;
            if (prod == 0) {
                prod = 1;
            }
        }
        ans = max(ans,ans2);
        return ans;

    }
};