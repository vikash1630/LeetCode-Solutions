class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 1;
        int n = nums.size();
        
        int temp = nums[0];
        while(i<n) {
            if (nums[i] != temp) {
                return temp;
            }
            temp = nums[i + 1];
            i = i + 2;
        }
        return temp;
    }
};