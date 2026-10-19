class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int ind = -1;
        while(i <= j) {
            int mid = (i + j)/2;
            if (nums[mid] < target) {
                i = mid + 1;
            }
            else {
                ind = mid;
                j = mid - 1;
            }
        }
        while (ind < nums.size() && nums[ind] == target) {
            ans.push_back(ind);
            ind++;
        }
        return ans;
    }
};