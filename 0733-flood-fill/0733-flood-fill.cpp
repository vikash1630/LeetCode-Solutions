class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = 1;

        // Up , right, down, left for row
        int drow[] = {-1,0,1,0};
        // Up , right, down, left for col
        int dcol[] = {0,1,0,-1};
        int inicolor = image[sr][sc];
        if (inicolor == color) return image;
        // BFS to update level wise, we can also prefer dfs
        while (q.size() != 0) {
            int k = q.size();
            for (int i = 0;i<k;i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                image[row][col] = color;
                for (int j = 0;j<4;j++)  {
                    int nrow = row + drow[j];
                    int ncol = col + dcol[j];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicolor && vis[nrow][ncol] == 0) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }

        return image;
    }
};