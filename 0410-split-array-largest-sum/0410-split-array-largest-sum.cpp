class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = 0;
        for (int i = 0;i<n;i++) {
            high += nums[i];
        }
        while (low <= high) {
            int mid = low + (high - low)/2;
            int Subarrays = isPossible(nums,mid);
            if (Subarrays > k) {
                // We can increase sum
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }

    int isPossible(vector<int>& nums,int maxSum) {
        int subarrays = 1;
        int sumPerArray = 0;
        for (int i = 0;i<nums.size();i++) {
            if (sumPerArray + nums[i] <= maxSum) {
                sumPerArray += nums[i];
            }
            else {
                subarrays++;
                sumPerArray = nums[i];
            }
        }
        return subarrays;
    }
};