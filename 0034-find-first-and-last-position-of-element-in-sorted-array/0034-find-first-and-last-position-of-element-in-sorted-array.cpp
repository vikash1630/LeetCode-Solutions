class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        // Classic question for floor and ciel
        int low = 0;
        int high = n - 1;
        int left = -1;
        int right = -1;
        int mid;
        bool flag = false;
        while (low <= high) {
            mid = low + (high - low)/2;
            if (nums[mid] == target) {
                flag = true;
                break;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if (!flag) {
            return {-1,-1};
        }
        int start = mid;
        while (mid < n && nums[mid] == target) {
            mid++;
        }
        right = mid - 1;
        while (start >=0 && nums[start] == target) {
            start--;
        }
        left = start + 1;
        
        return {left, right};
    }
};