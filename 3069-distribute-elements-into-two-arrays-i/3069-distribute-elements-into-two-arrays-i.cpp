class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int ind1 = 0;
        int ind2 = 0;
        int i = 2;
        while (i<n) {
            if (arr1[ind1] > arr2[ind2]) {
                arr1.push_back(nums[i]);
                ind1++;
            }
            else {
                arr2.push_back(nums[i]);
                ind2++;
            }
            i++;
        }
        for (auto &it: arr2) {
            arr1.push_back(it);
        }
        return arr1;
    }
};