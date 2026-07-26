class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        // Last row is our base case
        vector<int> front = triangle[n - 1];

        // Start from second last row
        for (int i = n - 2; i >= 0; i--) {

            vector<int> cur(i + 1);

            for (int j = 0; j <= i; j++) {

                int down = triangle[i][j] + front[j];

                int diagonal = triangle[i][j] + front[j + 1];

                cur[j] = min(down, diagonal);
            }

            front = cur;
        }

        return front[0];
    }
};