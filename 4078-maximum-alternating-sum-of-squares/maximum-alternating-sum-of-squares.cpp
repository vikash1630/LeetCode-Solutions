class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0;i<n;i++) nums[i] = nums[i] * nums[i];
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n - 1;
        long long sum1 = 0;
        long long sum2 = 0;
        while (i<j) {
            sum1 += (1LL * nums[i]);
            sum2 += (1LL * nums[j]);
            i++;
            j--;
        }
        if (i == j) sum2 += (1LL * nums[j]);
        return sum2 - sum1;
    }
};