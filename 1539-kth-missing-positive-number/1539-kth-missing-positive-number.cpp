class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int low = 0;
        int high = arr.size() -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            int check = arr[mid] - mid + 1; // means at any given ind the value should be ind + 1 if all present so to know how many before that index are not there we need to subtract element at that ind - possible element to be there

            // If check > k means more than k elements are missing before that index so answer must be in left
            if (check > k) {
                high = mid - 1;
            }
            // or else less than k elements are missing before that index so answer must be in right side
            else {
                low = mid + 1;
            }
        }

        // When high < low that means kth missing must be k + the element that actually should be at that position
        return high + 1 + k; 





        // Brute Forece O(n + k)
        // int cnt = 0;
        // int num = 1;
        // int missing = -1;
        // for (int i = 0;i<arr.size();i++) {   
        //     while (arr[i] != num) {
        //         cnt++;
        //         missing = num;
        //         if (cnt == k) return num;
        //         num++;
        //     }
        //     if (cnt == k) {
        //         return missing;
        //     }
        //     num++;
        // }
        // while (cnt != k) {
        //     missing = num;
        //     cnt++;
        //     num++;
        // }
        // return missing;
    }
};