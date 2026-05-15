class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        vector<int> vis(isConnected.size(),0);
        int st = nextZero(vis);
        while (st != -1) {
            cnt++;
            queue<int> q;
            vis[st] = 1;
            q.push(st);
            while (q.size() != 0) {
                int n = q.size();
                for (int i = 0;i<n;i++) {
                    int row = q.front();
                    q.pop();
                    for (int j = 0;j<isConnected[0].size();j++) {
                        if (isConnected[row][j] == 1) {
                            if (!vis[j]) {
                                vis[j] = 1;
                                q.push(j);
                            }
                        }
                    }
                }
            }
            st = nextZero(vis);
        }

        return cnt;
    }

    int nextZero(vector<int>& vis) {
        for (int i = 0;i<vis.size();i++) if (vis[i] == 0) return i;
        return -1;
    }
};