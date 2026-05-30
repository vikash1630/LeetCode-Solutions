class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adjL[n + 1];
        for (auto &it: times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adjL[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> minTime(n + 1, INT_MAX);
        minTime[0] = 0;
        minTime[k] = 0;
        while (!pq.empty()) {
            int timeReq = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto &it: adjL[node]) {
                int nextNode = it.first;
                int Time = it.second;
                if (Time + timeReq < minTime[nextNode]) {
                    minTime[nextNode] = Time + timeReq;
                    pq.push({minTime[nextNode], nextNode});
                }
            }
        }
        int ans = INT_MIN;
        for (int it = 1;it<minTime.size();it++) {
            if (minTime[it] == INT_MAX) return -1;
            ans = max(ans,minTime[it]);
        }
        return ans;
    }
};