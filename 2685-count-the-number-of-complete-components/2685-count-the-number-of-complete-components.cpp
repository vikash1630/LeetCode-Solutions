class Solution {
private:
    bool solve(vector<vector<int>> &adjL, int node, int n, vector<int> &visitedMain) {
        vector<int> count(n , 0);
        vector<int> vis(n , 0);
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        int countNodes = 1;
        visitedMain[node] = 1;
        while (q.size() != 0) {
            int m = q.size();
            for (int i = 0;i<m;i++) {
                int key = q.front();
                q.pop();
                for (auto it: adjL[key]) {
                    count[it]++;
                    if (vis[it] == 0) {
                        countNodes++;
                        q.push(it);
                        vis[it] = 1;
                        visitedMain[it] = 1;
                    }
                }
            }
        }
        int val = countNodes - 1;
        for (int i = 0;i<n;i++) {
            if (count[i] != val && count[i] != 0) return false;
        }
        return true;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjL(n);
        for (int i = 0;i<edges.size();i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        int ans = 0;
        vector<int> visitedMain(n, 0);
        for (int i = 0;i<n;i++) {
            if (visitedMain[i] == 0) {
                bool flag = solve(adjL, i, n, visitedMain);
                if (flag) ans++;
            }
        }
        return ans;
    }
};