class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m, 0));

        // Traverse First Row And last Row
        for (int i = 0;i<m;i++) {
            if (grid[0][i] == 1) dfs(n,m,0,i,vis,grid);
            if (grid[n - 1][i] == 1) dfs(n,m,n - 1,i,vis,grid);
        }

        // Traverse First Col And last Col
        for (int i = 0;i<n;i++) {
            if (grid[i][0] == 1 && vis[i][0] == 0) dfs(n,m,i,0,vis,grid);
            if (grid[i][m - 1] == 1 && vis[i][m - 1] == 0) dfs(n,m,i,m - 1,vis,grid);
        }

        // Count
        int ans = 0;
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    bfs(n,m,i,j,vis,grid,ans);
                }
            }
        }
        return ans;
    }

    void bfs(int n,int m,int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int& ans) {
        int drows[] = {-1,0,1,0};
        int dcols[] = {0,1,0,-1};
        queue<pair<int,int>> q;
        vis[row][col] = 1;
        ans++;
        q.push({row,col});
        while (q.size() != 0) {
            int k = q.size();
            for (int i = 0;i<k;i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int j = 0;j<4;j++) {
                    int nr = r + drows[j];
                    int nc = c + dcols[j];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                        vis[nr][nc] = 1;
                        ans++;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }

    void dfs(int n,int m,int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid) {
        int drows[] = {-1,0,1,0};
        int dcols[] = {0,1,0,-1};
        vis[row][col] = 1;
        for (int i = 0;i<4;i++) {
            int nrow = row + drows[i];
            int ncol = col + dcols[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                dfs(n,m,nrow,ncol,vis,grid);
            }
        }
    }
};