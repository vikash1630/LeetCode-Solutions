class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (matrix[i][j] == 1) {
                    int a = 0;
                    int b = 0;
                    int c = 0;
                    if (i >= 1) a = matrix[i - 1][j];
                    if (j >= 1) c = matrix[i][j - 1];
                    if (i >= 1 && j >= 1) b = matrix[i - 1][j - 1];
                    int sum = min(a, min(b, c));
                    matrix[i][j] = 1 + sum;
                }
            }
        }
        int ans = 0;
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};