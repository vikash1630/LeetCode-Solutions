class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ones = 0;
        int zeros = 0;
        int twos = 0;
        int n = nums.size();
        for (int i = 0;i<n;i++) {
            if (nums[i] == 0) zeros++;
            else if (nums[i] == 1) ones++;
            else twos++;
        }
        int i = 0;
        while (zeros > 0) {
            nums[i] = 0;
            i++;
            zeros--;
        }
        while (ones > 0) {
            nums[i] = 1;
            i++;
            ones--;
        }
        while (twos > 0) {
            nums[i] = 2;
            i++;
            twos--;
        }
    }
};