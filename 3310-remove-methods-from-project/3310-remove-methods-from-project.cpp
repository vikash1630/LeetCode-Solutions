class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build Adjacency List
        vector<vector<int>> adjL(n);
        for (const auto& edge : invocations) {
            adjL[edge[0]].push_back(edge[1]);
        }

        // Step 2: Standard BFS to mark all suspicious methods reachable from k
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(k);
        vis[k] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adjL[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Check if any non-suspicious method calls a suspicious method
        for (const auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            
            // Non-suspicious (u) points to suspicious (v) -> CANNOT remove any methods
            if (!vis[u] && vis[v]) {
                vector<int> allMethods(n);
                iota(allMethods.begin(), allMethods.end(), 0);
                return allMethods;
            }
        }

        // Step 4: Collect all non-suspicious methods
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};