class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        // vector<int> adj[];
        // for (int i = 0;i<V;i++) {
        //     for (int j = 0;j<graph[i].size();j++) {
        //         adj[i].push_back(graph[i][j]);
        //     }
        // }
        vector<int> vis(V,-1);

        // BFS
        for (int k = 0;k<V;k++) {
            if (vis[k] == -1) {
                bool flag = BFS(graph,vis,k);
                if (!flag) return false;
            }
        }
        
        return true;
    }

    bool BFS(vector<vector<int>>& graph,vector<int>& vis,int z) {
        queue<int> q;
        q.push(z);
        vis[z] = 0;
        while (q.size() != 0) {
            int n = q.size();
            for (int i = 0;i<n;i++) {
                int ele = q.front();
                int col = vis[ele];
                int setCol = -1;
                if (col == 1) setCol = 0;
                else setCol = 1;
                q.pop();
                for (int j = 0;j<graph[ele].size();j++) {
                    if (vis[graph[ele][j]] == -1) {
                        vis[graph[ele][j]] = setCol;
                        q.push(graph[ele][j]);
                    }
                    else {
                        if (vis[graph[ele][j]] == col) return false;
                    }
                }
            }
        }
        return true;
    }
};