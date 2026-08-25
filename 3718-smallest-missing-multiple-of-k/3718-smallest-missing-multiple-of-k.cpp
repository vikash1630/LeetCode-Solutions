class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int target = k;
        for (auto &it: nums) {
            if (it < target) continue;
            else if (it == target) {
                target += k; 
            }
            else break;
        }
        return target;
    }
};
