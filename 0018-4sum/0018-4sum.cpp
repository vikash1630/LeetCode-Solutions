class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for (int i = 0;i<=n-4;i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1;j<=n-3;j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1;
                int l = n - 1;
                while (k<l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k] == nums[k - 1]) k++;
                        while (k<l && nums[l + 1] == nums[l]) l--;
                    }
                    else if (sum > target) {
                        l--;
                    }
                    else k++;
                }
            }
        }
        

        return ans;

    }
};