class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while (low <= high) {
            int mid = low + (high - low)/2;
            double sum = 0;
            for (int i = 0;i<n;i++) {
                sum += ceil((double)nums[i] / mid);
            }
            if (sum > threshold) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};