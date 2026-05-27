class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Kahn's Algorithm in LeetCode and Stack method in gfg
        vector<int> adj[numCourses];
        vector<int> ans;
        vector<int> inDegree(numCourses,0);
        for (int i = 0;i<prerequisites.size();i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for (int i = 0;i<numCourses;i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        while (q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                int ele = q.front();
                q.pop();
                ans.push_back(ele);
                for (int j = 0;j<adj[ele].size();j++) {
                    inDegree[adj[ele][j]]--;
                    if (inDegree[adj[ele][j]] == 0) q.push(adj[ele][j]);
                }
            }
        }
        if (ans.size() == numCourses) return ans;
        return {};
    }
};