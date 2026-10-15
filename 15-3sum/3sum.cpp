class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = 1;
        int k = n - 1;
        vector<vector<int>> ans;
        while (i < n - 2) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] == -nums[i]) {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    // Skip Duplicates
                    while (j < n - 1 && nums[j] == nums[j + 1])
                        j++;
                    while (k > j && nums[k] == nums[k - 1])
                        k--;
                    k--;
                    j++;
                }
                else if (nums[j] + nums[k] > -nums[i]) {
                    while (k > j && nums[k] == nums[k - 1]) k--;
                    k--;
                }
                else {
                    while (j < n - 1 && nums[j] == nums[j + 1]) j++;
                    j++;
                }
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
            i++;
        }
        return ans;
    }
};