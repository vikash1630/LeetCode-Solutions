class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i<n && j<m) {
            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i<n) {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j<m) {
            ans.push_back(nums2[j]);
            j++;
        }
        double res;
        int p = ans.size();
        if (p % 2 == 0) {
            double a = ans[(p - 1)/2];
            double b = ans[p/2];
            res = (a + b)/2;
        }
        else{
            res = ans[p/2];
        }
        return res;
    }
};