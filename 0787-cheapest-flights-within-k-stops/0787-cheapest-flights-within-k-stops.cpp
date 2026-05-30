class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adjL[n];
        for (int i = 0;i<flights.size();i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int dis = flights[i][2];
            adjL[u].push_back({v,dis});
        }
        vector<int> price(n,INT_MAX);
        // stops,node,price
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int stops = node.first;
            int ele = node.second.first;
            int fare = node.second.second;
            if (stops > k) continue;
            for (auto &it : adjL[ele]) {
                int v = it.first;
                int priceReq = it.second;
                if (fare + priceReq < price[v] && stops <= k) {
                    price[v] = fare + priceReq;
                    q.push({stops + 1,{v,price[v]}});
                }

            }
        }



        // {priceFromSrc, node}
        // queue<pair<int,int>> q;
        // int stops = -1;
        // q.push({0,src});
        // while (q.size() != 0) {
        //     int m = q.size();
        //     for (int i = 0;i<m;i++) {
        //         auto node = q.front();
        //         q.pop();
        //         int currPrice = node.first;
        //         int currEle = node.second;
        //         if (stops == k) {
        //             if (price[dst] == INT_MAX) return -1;
        //             else return price[dst];
        //         }
        //         for (auto &it:adjL[currEle]) {
        //             int toNode = it.first;
        //             int priceReq = it.second;
        //             if (currPrice + priceReq < price[toNode]) {
        //                 price[toNode] = currPrice + priceReq;
        //                 q.push({price[toNode],toNode});
        //             }
        //         }
        //     }
        //     stops++;
        // }
        return (price[dst] == INT_MAX) ? -1 : price[dst];
    }
};