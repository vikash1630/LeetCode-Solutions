class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adjRev[V];
        vector<int> inDegree(V,0);
        for (int i = 0;i<V;i++) {
            for (int j = 0;j<graph[i].size();j++) {
                adjRev[graph[i][j]].push_back(i);
                inDegree[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0;i<V;i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                int ele = q.front();
                q.pop();
                ans.push_back(ele);
                for (int j = 0;j<adjRev[ele].size();j++) {
                    inDegree[adjRev[ele][j]]--;
                    if (inDegree[adjRev[ele][j]] == 0) q.push(adjRev[ele][j]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};