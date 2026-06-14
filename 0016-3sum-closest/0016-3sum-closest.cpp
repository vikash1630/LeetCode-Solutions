class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return -1;
        int left = 0;
        int right = n - 1;
        long long ans = INT_MIN + 1;
        for (int i = 0;i<n-2;i++) {
            for (int j = i + 1;j<n-1;j++) {
                for (int k = j + 1;k<n;k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if ( abs(sum - target) < abs(ans - target) ) ans = sum;
                }
            }
        }
        return ans;
    }
};