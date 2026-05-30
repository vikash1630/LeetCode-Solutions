class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adjL[n];
        const long long MOD = 1e9 + 7;

        for (auto &it : roads) {
            long long u = it[0];
            long long v = it[1];
            long long wt = it[2];
            adjL[u].push_back({v,wt});
            adjL[v].push_back({u,wt});
        }

        long long src = 0;

        priority_queue<
            pair<long long,long long>,
            vector<pair<long long,long long>>,
            greater<pair<long long,long long>>
        > pq;

        vector<long long> NoOfWays(n,0);
        vector<long long> shortestWt(n,LLONG_MAX);

        pq.push({0,src});
        NoOfWays[src] = 1;
        shortestWt[src] = 0;

        while (!pq.empty()) {
            long long wt = pq.top().first;
            long long ele = pq.top().second;
            pq.pop();

            if (wt > shortestWt[ele]) continue;   // FIX

            for (auto &it: adjL[ele]) {
                long long nextNode = it.first;
                long long wtReq = it.second;

                if ((wtReq + wt) == shortestWt[nextNode]) {
                    NoOfWays[nextNode] =
                        (NoOfWays[nextNode] + NoOfWays[ele]) % MOD; // FIX
                }
                else if ((wtReq + wt) < shortestWt[nextNode]) {
                    NoOfWays[nextNode] = NoOfWays[ele];
                    shortestWt[nextNode] = wtReq + wt; // FIX
                    pq.push({shortestWt[nextNode], nextNode});
                }
            }
        }

        return NoOfWays[n - 1] % MOD;
    }
};