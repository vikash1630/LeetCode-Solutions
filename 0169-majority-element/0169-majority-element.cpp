class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ele;
        int i = 0;
        int n = nums.size();
        while (i<n) {
            if (cnt == 0) {
                ele = nums[i];
                cnt++;
            }
            else if (ele != nums[i]) {
                cnt--;
            }
            else {
                cnt++;
            }
            i++;
        }
        return ele;

        // Better Solution
        // int n = nums.size();
        // unordered_map<int,int> mpp;
        // int i;
        // for (i = 0;i<n;i++) {
        //     mpp[nums[i]]++;
        // }
        // int k;
        // if (n%2 == 1) k = n/2 + 1;
        // else k = n/2;
        // for (auto it: mpp) {
        //     if (it.second >= k) return it.first;
        // }
        // return -1;
    }
};