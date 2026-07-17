class DisJointSet {
public:
    vector<int> parent, size;
    DisJointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0;i<n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUlp(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUlp(parent[node]);
    }

    void unionBySize(int u, int v) {
        int Ulp_u = findUlp(u);
        int Ulp_v = findUlp(v);
        if (Ulp_u == Ulp_v) return;
        if (size[Ulp_u] > size[Ulp_v]) {
            // Join to u
            size[Ulp_u] += size[Ulp_v];
            parent[Ulp_v] = Ulp_u;
        }
        else {
            // Join to v
            size[Ulp_v] += size[Ulp_u];
            parent[Ulp_u] = Ulp_v;
        }

    }


};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisJointSet dis(n);
        // mail to ind
        unordered_map<string, int> mpp;
        for (int i = 0;i<n;i++) {
            for (int j = 1;j<accounts[i].size();j++) {
                string mail = accounts[i][j];
                if (mpp.find(mail) != mpp.end()) {
                    // Node Exists;
                    dis.unionBySize(i, mpp[mail]);
                }
                else {
                    mpp[mail] = i;
                }
            }
        }

        // every index has merged mails and if someone being merged then that index goes empty
        vector<vector<string>> mergedMails(n);
        for (auto &it: mpp) {
            string mail = it.first;
            int node = it.second;
            int parNode = dis.findUlp(node);
            mergedMails[parNode].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0;i<n;i++) {
            if (mergedMails[i].size() == 0) continue;
            vector<string> temp;
            // Add name
            temp.push_back(accounts[i][0]);
            // Sort mails and then add 
            sort(mergedMails[i].begin(), mergedMails[i].end());
            for (auto &str: mergedMails[i]) {
                temp.push_back(str);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};