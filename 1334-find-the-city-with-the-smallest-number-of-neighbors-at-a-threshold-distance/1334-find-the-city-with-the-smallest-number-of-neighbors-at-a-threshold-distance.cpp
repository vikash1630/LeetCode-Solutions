class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // It is a classic question of multiple source to multiple destination with the shortest time so we canuse Floyd Warshall algoritham
        vector<pair<int,int>> adjL[n];
        for (auto &it: edges) {
            int u = it[0];
            int v = it[1];
            int dis = it[2];
            adjL[u].push_back({v,dis});
            adjL[v].push_back({u,dis});
        }
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<n;j++) {
                if (i == j) {
                    dist[i][j] = 0;
                    continue;
                }
                for (auto &it : adjL[i]) {
                    int ele = it.first;
                    int dis = it.second;
                    if (ele == j) dist[i][j] = dis;
                }
            }
        }

        for (int via = 0;via<n;via++) {
            for (int i = 0;i<n;i++) {
                for (int j = 0;j<n;j++) {
                    if ( dist[i][via] + dist[via][j] < dist[i][j] )  dist[i][j] = dist[i][via] + dist[via][j];
                }
            }
        }
        // No of Cities , which city
        pair<int,int> ans;
        ans.first = INT_MAX;
        ans.second = -1;
        for (int i = 0;i<n;i++) {
            int cntCities = 0;
            for (int j = 0;j<n;j++) {
                if (dist[i][j] <= distanceThreshold) cntCities++;
            }
            if (cntCities < ans.first) {
                ans.first = cntCities;
                ans.second = i;
            }
            else if (cntCities == ans.first) ans.second = i;
        }

        return ans.second;
    }
};