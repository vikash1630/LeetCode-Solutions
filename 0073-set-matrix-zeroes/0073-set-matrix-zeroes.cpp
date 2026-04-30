class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool RowZero = false;
        bool ColZero = false;
        // Traverse if first row has zeros
        for (int i = 0;i<n;i++) {
            if (matrix[i][0] == 0) {
                RowZero = true;
                break;
            }
        }
        // Traverse if first colounm has zeros
        for (int i = 0;i<m;i++) {
            if (matrix[0][i] == 0) {
                ColZero = true;
                break;
            }
        }

        // Mark the Row or col Zero for which whole will Zero
        for (int i = 1;i<n;i++) {
            for (int j = 1;j<m;j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Mark whole Rows Zero where ever Satisfied
        for (int i = 1;i<n;i++) {
            if (matrix[i][0] == 0) {
                int k = 0;
                while (k<m) {
                    matrix[i][k] = 0;
                    k++;
                }
            }
        }

        // Mark whole coloumn Zero where ever Satisfied
        for (int i = 1;i<m;i++) {
            if (matrix[0][i] == 0) {
                int k = 0;
                while (k<n) {
                    matrix[k][i] = 0;
                    k++;
                }
            }
        }

        if (RowZero) {
            int k = 0;
            while (k<n) {
                matrix[k][0] = 0;
                k++;
            }
        }

        if (ColZero) {
            int k = 0;
            while (k<m) {
                matrix[0][k] = 0;
                k++;
            }
        }

        // Brute Force
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<vector<int>> zeros(n, vector<int>(m));
        // for (int i = 0;i<n;i++) {
        //     for (int j = 0;j<m;j++) {
        //         zeros[i][j] = matrix[i][j];
        //     }
        // }
        // for (int i = 0;i<n;i++) {
        //     for (int j = 0;j<m;j++) {
        //         if (matrix[i][j] == 0) {
        //             makeZeros(zeros,i,j,n,m);
        //         }
        //     }
        // }
        // matrix = zeros;

    }
    // void makeZeros(vector<vector<int>>& ans, int i,int j,int n,int m) {
    //     for (int k = 0;k<m;k++) {
    //         ans[i][k] = 0;
    //     }
    //     for (int k = 0;k<n;k++) {
    //         ans[k][j] = 0;
    //     }
    // }
};