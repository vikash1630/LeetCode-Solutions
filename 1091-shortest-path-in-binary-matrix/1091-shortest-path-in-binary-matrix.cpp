class Solution {
// DFS is not optimal so we prefer BFS
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int drows[] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int dcols[] = {0, 1, 0, -1, -1, 1, 1, -1};
        int dis = 0;
        int ans = INT_MAX;
        // {{parentrow,parentcol},{currrow,currcol}}
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if (n == 0) return -1;
        if (grid[0][0] == 1) return -1;
        if (grid[n - 1][n - 1] == 1) return -1;
        q.push({0,0});
        vis[0][0] = 1;
        while (q.size() != 0) {
            dis++;
            int m = q.size();
            for (int i = 0;i<m;i++) {
                auto node = q.front();
                q.pop();
                int row = node.first;
                int col = node.second;
                if (row == n - 1 && col == n - 1) {
                    ans = min(dis,ans);
                }
                for (int j = 0;j<8;j++) {
                    int nrow = row + drows[j];
                    int ncol = col + dcols[j];
                    if (nrow < n && nrow >= 0 && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
// private:
//     void dfs(int row, int col, int n, int dis, int &ans,
//              vector<vector<int>> &pathVis,
//              vector<vector<int>> &grid) {

//         int drows[] = {-1, 0, 1, 0, -1, -1, 1, 1};
//         int dcols[] = {0, 1, 0, -1, -1, 1, 1, -1};

//         dis++;

//         if (row == n - 1 && col == n - 1) {
//             ans = min(ans, dis);
//             return;
//         }

//         for (int i = 0; i < 8; i++) {
//             int nrow = row + drows[i];
//             int ncol = col + dcols[i];

//             if (nrow >= 0 && nrow < n &&
//                 ncol >= 0 && ncol < n &&
//                 pathVis[nrow][ncol] == 0 &&
//                 grid[nrow][ncol] == 0) {

//                 pathVis[nrow][ncol] = 1;

//                 dfs(nrow, ncol, n, dis, ans, pathVis, grid);

//                 pathVis[nrow][ncol] = 0;
//             }
//         }
//     }

// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();

//         if (n == 0 || grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
//             return -1;

//         int ans = INT_MAX;

//         vector<vector<int>> pathVis(n, vector<int>(n, 0));
//         pathVis[0][0] = 1;

//         dfs(0, 0, n, 0, ans, pathVis, grid);

//         return (ans == INT_MAX) ? -1 : ans;
//     }
// };