class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        int mid;
        while (low <= high) {
            mid = low + (high - low)/2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            // If left Half is Sorted
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid]) {
                    // target is in left Sorted Part
                    high = mid - 1;
                }
                else {
                    // Target is in right Side 
                    low = mid + 1;
                }
            }
            // If Right Half is Sorted
            else {
                if (target >= nums[mid] && target <= nums[high]) {
                    // target is in Right sorted part
                    low = mid + 1;
                }
                else {
                    // Target is in left side
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};