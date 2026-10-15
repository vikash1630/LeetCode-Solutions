class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;

        while (i <= n - 4) {
            int j = i + 1;
            while (j <= n - 3) {
                int k = j + 1;
                int l = n - 1;
                int sum = nums[i] + nums[j];
                while (k < l) {
                    if ( (1LL * nums[k]) + (1LL * nums[l]) == (1LL * target) - (1LL * sum) )  {
                            ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                            // skip duplicates
                            while (k <= n - 2 && nums[k] == nums[k + 1])
                                k++;
                            while (l > k && nums[l] == nums[l - 1])
                                l--;
                            k++;
                            l--;
                        }
                    else if ((1LL * nums[k]) + (1LL * nums[l]) >
                             (1LL * target) - (1LL * sum)) {
                        l--;
                    } else
                        k++;
                }
                while (j <= n - 3 && nums[j] == nums[j + 1])
                    j++;
                j++;
            }
            while (i <= n - 3 && nums[i] == nums[i + 1])
                i++;
            i++;
        }
        return ans;
    }
};