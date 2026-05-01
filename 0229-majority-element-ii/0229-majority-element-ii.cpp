class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0;i<n;i++) {
            if (cnt1 == 0 && ele2 != nums[i]) {
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if (cnt2 == 0 && ele1 != nums[i]) {
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if (ele1 == nums[i]) cnt1++;
            else if (ele2 == nums[i]) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        if (cnt1 == 0 && cnt2 == 0) {
            return {};
        }
        cnt1 = 0;
        cnt2 = 0;
        int target = (n/3);
        if (ele1 == ele2) {
            for (int i = 0;i<n;i++) {
                if (nums[i] == ele1) cnt1++;
                if (cnt1 > target) return {ele1};
            }
        }
        for (int i = 0;i<n;i++) {
            if (nums[i] == ele1) cnt1++;
            if (nums[i] == ele2) cnt2++;
        }
        if (cnt1 > target) ans.push_back(ele1);
        if (cnt2 > target) ans.push_back(ele2);
        return ans;

    }
};