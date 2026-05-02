class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int pos = n + m - 1;
        while (i>=0 && j>=0) {
            if (nums2[j] >= nums1[i]) {
                nums1[pos] = nums2[j];
                pos--;
                j--;
            }
            else {
                nums1[pos] = nums1[i];
                pos--;
                i--;
            }
        }
        while(j>=0) {
            nums1[pos] = nums2[j];
            pos--;
            j--;
        }
    }
};