class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = 0; // Total Weight As worse case is to ship in one day so capacity should be total weight to ship in one day
        for (int i = 0;i<weights.size();i++) {
            high += weights[i];
        }
        int capacity = high;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (isPossible(weights,days,mid)) {
                capacity = mid; // Possible answer
                high = mid - 1;
                // Check if is it possible to ship in less than this as we required minimum
            }
            else {
                low = mid + 1;
            }
        }
        return capacity;
    }

    bool isPossible(vector<int>& weights,int days,int capacity) {
        int totDay = 1;
        int sum = 0;
        for (int weight : weights) {
            sum += weight;
            if (sum > capacity) {
                totDay++;
                sum = weight;
            }
        }
        if (totDay <= days) return true;
        return false;
    }
};