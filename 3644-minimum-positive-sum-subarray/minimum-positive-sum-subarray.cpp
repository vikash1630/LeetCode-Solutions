class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = -1;
        int n = nums.size();
        for (int i = 0;i<n;i++) {
            int sum = 0;
            int size = 0;
            for (int j = i;j<n;j++) {
                sum += nums[j];
                size++;
                if (size > r) break;
                if (size >= l) {
                    if (sum > 0) {
                        if (ans == -1 || ans > sum) ans = sum;
                    }
                }
            }
        }
        return ans;
    }
};