class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 0;
        for (int i : nums) {
            if (candidate == i) count++;
            else {
                count--;
            }
            if (count == -1) {
                candidate = i;
                count = 1;
            }
        }
        return candidate;
    }
};