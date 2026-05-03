class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int check = INT_MAX;
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low++;
                high--;
                ans = min(ans,nums[mid]);
                continue;
            }
            if (nums[low] <= nums[mid]) {
                check = nums[low];
                ans = min(ans,check);
                low = mid + 1;
            }
            else {
                check = nums[mid];
                ans = min(ans,check);
                high = mid - 1;
            }
        }
        return ans;
    }
};