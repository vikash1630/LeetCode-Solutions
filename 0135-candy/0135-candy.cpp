class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = 1;
        while (i<n) {
            if (ratings[i] == ratings[i-1]) {
                sum = sum + 1;
                i++;
                continue;
            }
            int peak = 1;
            while (i<n && ratings[i] > ratings[i - 1]) {
                peak = peak + 1;
                sum = sum + peak;
                i++;
            }
            int down = 1;
            while (i<n && ratings[i] < ratings[i - 1]) {
                sum = sum + down;
                i++;
                down = down + 1;
            }
            if (down > peak) {
                sum = sum + down - peak;
            }

        }

        return sum;



        // Brute Force
        // vector<int> candies(n, 1);

        // // Left → Right
        // for (int i = 1; i < n; i++) {
        //     if (ratings[i] > ratings[i - 1]) {
        //         candies[i] = candies[i - 1] + 1;
        //     }
        // }

        // // Right → Left
        // for (int i = n - 2; i >= 0; i--) {
        //     if (ratings[i] > ratings[i + 1]) {
        //         candies[i] = max(candies[i], candies[i + 1] + 1);
        //     }
        // }

        // return accumulate(candies.begin(), candies.end(), 0);
    }
};