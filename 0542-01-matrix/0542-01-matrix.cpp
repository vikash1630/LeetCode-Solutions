class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int drows[] = {-1,0,1,0};
        int dcols[] = {0,1,0,-1};
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (mat[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }

        while (q.size() != 0) {
            int k = q.size();
            for (int i = 0;i<k;i++) {
                int row = q.front().first.first;
                int col = q.front().first.second;
                int dis = q.front().second;
                q.pop();
                if (mat[row][col] == 1) {
                    ans[row][col] = dis;
                }
                for (int j = 0;j<4;j++) {
                    int r = row + drows[j];
                    int c = col + dcols[j];
                    if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]) {
                        vis[r][c] = 1;
                        q.push({{r,c},dis + 1});
                    }
                }   
            }
        }

        return ans;
    }
};