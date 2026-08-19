class Solution {
private:
    bool check(vector<int>& arr, int l, int r) {
        for (int i = l; i <= r; i++) {
            if (arr[i] == 1) return false;
        }
        return true;
    }

public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // Every completely empty row can accommodate 2 families
        int ans = 2 * n;

        unordered_map<int, vector<int>> rows;

        for (auto &seat : reservedSeats) {
            rows[seat[0]].push_back(seat[1]);
        }

        for (auto &[row, seats] : rows) {

            vector<int> occupied(11, 0);

            for (int col : seats) {
                occupied[col] = 1;
            }

            bool left  = check(occupied, 2, 5);
            bool right = check(occupied, 6, 9);
            bool mid   = check(occupied, 4, 7);

            // Initially counted this row as 2.
            // Recalculate its actual contribution.
            if (left && right) {
                // Still 2
            }
            else if (left || mid || right) {
                ans--;
            }
            else {
                ans -= 2;
            }
        }

        return ans;
    }
};