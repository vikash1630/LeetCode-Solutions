class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        int cnt = 0;
        int i = 0;
        while (i<n) {
            if (nums[i] == 1) cnt++;
            else {
                maxi = max(cnt,maxi);
                cnt = 0;
            }
            i++;
        }
        maxi = max(maxi,cnt);
        return maxi;
    }
};