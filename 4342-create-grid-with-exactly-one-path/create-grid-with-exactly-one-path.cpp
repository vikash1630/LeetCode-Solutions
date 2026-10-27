class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> mat(m, vector<char>(n, '#'));
        
        for (int i = 0; i < m; i++) {
            mat[i][0] = '.';
        }

        for (int j = 1; j < n; j++) {
            mat[m - 1][j] = '.';
        }

        vector<string> ans;
        for (int i = 0; i < m; i++) {
            string str = "";
            for (int j = 0; j < n; j++) {
                str += mat[i][j];
            }
            ans.push_back(str);
        }

        return ans;
    }
};

