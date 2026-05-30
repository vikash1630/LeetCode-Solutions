class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long MOD = 1e9 + 7;

        vector<pair<int,int>> adj[n];

        for (auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip stale entries
            // if (dis > dist[node]) continue;

            for (auto &it : adj[node]) {

                int adjNode = it.first;
                long long wt = it.second;

                // Found shorter path
                if (dis + wt < dist[adjNode]) {

                    dist[adjNode] = dis + wt;
                    ways[adjNode] = ways[node];

                    pq.push({dist[adjNode], adjNode});
                }

                // Found another shortest path
                else if (dis + wt == dist[adjNode]) {

                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};