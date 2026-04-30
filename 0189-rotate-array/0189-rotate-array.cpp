class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        int i = n - k;
        vector<int> ans(n);
        while (i<n) {
            ans[i - (n-k)] = nums[i];
            i++;
        }
        int j = i - (n-k);
        i = 0;
        while (i<n-k) {
            ans[j] = nums[i];
            i++;
            j++;
        }
        nums = ans;
        
    }
};