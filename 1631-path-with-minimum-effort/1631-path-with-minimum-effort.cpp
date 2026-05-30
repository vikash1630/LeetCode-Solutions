class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int drows[] = {-1,0,1,0};
        int dcols[] = {0,1,0,-1};
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0] = 0;
        pq.push({0,{0,0}});
        while (pq.size() != 0) {
            auto node = pq.top();
            pq.pop();
            int diff = node.first;
            int row = node.second.first;
            int col = node.second.second;
            if (row == n - 1 && col == m - 1) return diff;
            for (int i = 0;i< 4;i++) {
                int nrow = row + drows[i];
                int ncol = col + dcols[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    int effort = abs(heights[row][col] - heights[nrow][ncol]);
                    int newEffort = max(effort,diff);
                    if (newEffort < dis[nrow][ncol]) {
                        dis[nrow][ncol] = newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};