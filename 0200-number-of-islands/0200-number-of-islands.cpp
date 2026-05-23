class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(n,m,i,j,vis,grid);
                    islands++;
                }
            }
        }
        return islands;
    }

    void dfs(int n,int m,int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid) {
        int drows[] = {-1,0,1,0};
        int dcols[] = {0,1,0,-1};
        vis[row][col] = 1;
        for (int i = 0;i<4;i++) {
            int nr = row + drows[i];
            int nc = col + dcols[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && vis[nr][nc] == 0) dfs(n,m,nr,nc,vis,grid);
        }
    }
};