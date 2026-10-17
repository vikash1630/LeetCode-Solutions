class Solution {
private:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({digitSum(nums[i]), nums[i]});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> targetIndex;
        for (int i = 0; i < n; i++) {
            targetIndex[arr[i].second] = i;
        }

        vector<int> perm(n);
        for (int i = 0; i < n; i++) {
            perm[i] = targetIndex[nums[i]];
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || perm[i] == i)
                continue;

            int j = i;
            int cycle = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = perm[j];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};