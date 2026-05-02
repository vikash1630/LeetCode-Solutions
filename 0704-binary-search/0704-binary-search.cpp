class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = high + (low - high)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high--;
            else low++;
        }
        return -1;
    }
};