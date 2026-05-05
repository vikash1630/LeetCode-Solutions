class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 0;
        int num = 1;
        int missing = -1;
        for (int i = 0;i<arr.size();i++) {   
            while (arr[i] != num) {
                cnt++;
                missing = num;
                if (cnt == k) return num;
                num++;
            }
            if (cnt == k) {
                return missing;
            }
            num++;
        }
        while (cnt != k) {
            missing = num;
            cnt++;
            num++;
        }
        return missing;
    }
};