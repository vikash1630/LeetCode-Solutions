class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            // Check Which half to discard 
            if (mid < n - 1 && nums[mid] == nums[mid + 1]) {
                // Mid is double with its pair at right
                // It means mid + 1 should be at even index so remaining are paired at right
                if ((mid+1)%2 == 0) {
                    // Means right half elements are paired 
                    // Now single element in right half
                    high = mid - 1;
                }
                else {
                    // Means right half are odd number of elements
                    low = mid + 1;
                }
            }
            else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                // Mid is double with its pair at left
                // It means mid should be at even index o remaining are paired at left
                if (mid%2 == 0) {
                    // Means right half element are paired
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                return nums[mid];
            }
        }
        return -1;
    }
};