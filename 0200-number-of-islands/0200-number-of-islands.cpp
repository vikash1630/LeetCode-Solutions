class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int nr[] = {1, -1, 0, 0};
        int nc[] = {0, 0, 1, -1};
        int ans = 0;
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (vis[i][j] == 1) continue;
                if (grid[i][j] == '0') {
                    vis[i][j] = 1;
                    continue;
                }
                // Row, Col
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                while (q.size() != 0) {
                    int p = q.size();
                    for (int k = 0;k<p;k++) {
                        auto node = q.front();
                        q.pop();
                        int row = node.first;
                        int col = node.second;
                        for (int a = 0;a<4;a++) {
                            int nextRow = row + nr[a];
                            int nextCol = col + nc[a];
                            if (nextCol >= 0 && nextRow >= 0 && nextCol < m && nextRow < n && grid[nextRow][nextCol] == '1' && vis[nextRow][nextCol] == 0) {
                                q.push({nextRow, nextCol});
                                vis[nextRow][nextCol] = 1;
                            }
                        }
                    }
                
                }
            }
        }
    return ans;
    }
};