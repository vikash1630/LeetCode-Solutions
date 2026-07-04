class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adjL(n + 1);

        for (auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adjL[u].push_back({v, wt});
            adjL[v].push_back({u, wt});
        }

        vector<int> vis(n + 1, 0);

        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto &it : adjL[node]) {

                int neigh = it.first;
                int wt = it.second;

                ans = min(ans, wt);

                if (!vis[neigh]) {
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }

        return ans;
    }
};