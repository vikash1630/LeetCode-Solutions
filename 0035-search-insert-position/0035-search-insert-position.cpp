class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Classic Question To find Lower Bound
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = high + (low - high)/2;
            if (nums[mid] >= target) {
                ans = min(ans,mid);
                high--;
            }
            else low++;
        }
        return ans;
    }
};