class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for (int i = 0;i<n;i++) {
            sum += nums[i];
            if (sum < 0) {
                maxi = max(maxi,sum);
                sum = 0;
            }
            else {
                maxi = max(sum,maxi);
            }
        }
        return maxi;
    }
};