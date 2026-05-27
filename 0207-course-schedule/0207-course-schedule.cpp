class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Kahn's Algorithm in LeetCode and Stack method in gfg
        int V = numCourses;
        vector<int> InDegree(V,0);
        vector<int> adj[V];
        for (int i = 0;i<prerequisites.size();i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            InDegree[prerequisites[i][1]]++;
        }
        queue<int> q;
        for (int i = 0;i<V;i++) {
            if (InDegree[i] == 0) {
                q.push(i);
            }
        }
        while (q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                int ele = q.front();
                q.pop();
                numCourses--;
                for (int j = 0;j<adj[ele].size();j++) {
                    InDegree[adj[ele][j]]--;
                    if (InDegree[adj[ele][j]] == 0) q.push(adj[ele][j]);
                }
            }
        }

        if (numCourses == 0) return true;
        return false;
    }
};