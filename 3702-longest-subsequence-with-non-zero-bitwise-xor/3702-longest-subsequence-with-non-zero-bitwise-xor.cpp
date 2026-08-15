class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_Xor = 0;
        bool flag = false;
        for (auto &it: nums) {
            if (it != 0) {
                flag = true;
            }
            total_Xor = total_Xor ^ it;
        }
        if (flag == false) return 0;
        if (total_Xor != 0) return nums.size();
        return nums.size() - 1;
    }
};