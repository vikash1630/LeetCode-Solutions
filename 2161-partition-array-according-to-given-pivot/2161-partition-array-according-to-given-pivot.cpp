class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> before;
        vector<int> after;
        vector<int> ans;
        int cnt = 0;
        for (int i = 0;i<nums.size();i++) {
            if (nums[i] < pivot) before.push_back(nums[i]);
            else if (nums[i] > pivot) after.push_back(nums[i]);
            else cnt++;
        }
        int i = 0;
        while (i < before.size()) {
            ans.push_back(before[i]);
            i++;
        }
        while (cnt > 0) {
            ans.push_back(pivot);
            cnt--;
        }
        i = 0;
        while (i < after.size()) {
            ans.push_back(after[i]);
            i++;
        }

        return ans;
    }
};