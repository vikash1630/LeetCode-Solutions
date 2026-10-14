class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i : nums) mpp[i]++;
        int n = nums.size();
        vector<int> ans;
        for (auto it: mpp) {
            if (it.second > n/3) ans.push_back(it.first);
            if (ans.size() == 2) break;
        }
        return ans;
    }
};