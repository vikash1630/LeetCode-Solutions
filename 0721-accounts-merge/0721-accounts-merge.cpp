#include <bits/stdc++.h>
using namespace std;

class DisJointSet {
public:
    vector<int> parent, size;

    DisJointSet(int n) {

        // Create arrays of size n
        parent.resize(n);
        size.resize(n);

        /*
        ❌ YOUR MISTAKE:

        for (int i = 0; i <= n; i++)

        parent has indices:
        0 .... n-1

        But i = n tries to access parent[n]
        which DOES NOT EXIST.

        This causes Runtime Error.

        Rule:
        If vector size is n,
        loop should always be

        i < n
        */

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUlpar(int node) {

        // Base Case
        if (parent[node] == node)
            return node;

        // Path Compression
        return parent[node] = findUlpar(parent[node]);
    }

    void unionBySize(int u, int v) {

        int ulp_u = findUlpar(u);
        int ulp_v = findUlpar(v);

        // Already in same component
        if (ulp_u == ulp_v)
            return;

        /*
        Attach smaller tree under bigger tree.
        */

        if (size[ulp_u] >= size[ulp_v]) {

            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];

        } else {

            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        // email -> account index
        unordered_map<string, int> mpp;

        DisJointSet dis(n);

        /*
        STEP 1

        Traverse every email.

        If email seen first time:
            store email -> account index

        Else:
            Same email belongs to two accounts.
            Merge those accounts.
        */

        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if (mpp.find(mail) == mpp.end()) {

                    mpp[mail] = i;

                } else {

                    int previousNode = mpp[mail];

                    dis.unionBySize(i, previousNode);
                }
            }
        }

        /*
        mergedMails[parent] stores all mails
        belonging to that connected component.
        */

        vector<vector<string>> mergedMails(n);

        for (auto &it : mpp) {

            string mail = it.first;
            int node = it.second;

            int parentNode = dis.findUlpar(node);

            mergedMails[parentNode].push_back(mail);
        }

        vector<vector<string>> ans;

        /*
        ❌ YOUR MISTAKE:

        You wrote

        vector<vector<string>> ans;

        ans[i].push_back(...)

        ans is EMPTY.

        Size = 0.

        There is NO ans[i].

        You either need

        vector<vector<string>> ans(n);

        OR

        Create a temporary vector
        then push it into ans.

        We use second approach.
        */

        for (int i = 0;i<n;i++) {
            int m = mergedMails[i].size();
            if (m == 0) continue;
            vector<string> temp;
            sort(mergedMails[i].begin(), mergedMails[i].end());
            string name = accounts[i][0];
            temp.push_back(name);
            for (auto &it: mergedMails[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);

        }


        return ans;
    }
};