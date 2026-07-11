class DisJointSet {

public:
    vector<int> parent, size;
    DisJointSet(int V) {
        parent.resize(V);
        size.resize(V);
        for (int i = 0;i<V;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUpar(int node) {
        if (node == parent[node]) return node;
        parent[node] = findUpar(parent[node]);
        return parent[node];
    }

    void UnionBySize(int u, int v) {
        int Ulp_u = findUpar(u);
        int Ulp_v = findUpar(v);

        if (Ulp_v == Ulp_u) return;

        if (size[Ulp_v] < size[Ulp_u]) {
            parent[Ulp_v] = Ulp_u;
            size[Ulp_u] += size[Ulp_v];
        }
        else {
            parent[Ulp_u] = Ulp_v;
            size[Ulp_v] += size[Ulp_u];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet dis(n);
        int m = connections.size();
        int extra = 0;
        int ConnectedConnections = 0;
        for (int i = 0;i<connections.size();i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            if (dis.findUpar(u) != dis.findUpar(v)) {
                dis.UnionBySize(u, v);
            }                
            else extra++;
        }
        int Components = 0;
        // Count How Many Unique Parents exists = Componenets
        for (int i = 0;i<n;i++) {
            if (dis.findUpar(i) == i) Components++;
        }
        // To Connect n graphs we need n - 1 sub graphs,  Think as nodes that is why we do Components - 1
        if (extra >= Components - 1) return Components - 1;
        return -1;
    }
};



















