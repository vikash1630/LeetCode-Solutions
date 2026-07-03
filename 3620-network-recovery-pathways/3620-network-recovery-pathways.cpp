class Solution {
public:

    // ---------------------------------------------------------
    // This function checks whether it is possible to obtain
    // a path whose minimum edge weight is at least 'mid'.
    //
    // We simply REMOVE every edge whose weight < mid.
    //
    // Then we compute the shortest path from 0 to n-1.
    //
    // If shortest distance <= k
    //      -> mid is achievable.
    //
    // Otherwise
    //      -> impossible.
    // ---------------------------------------------------------
    bool possible(
        int mid,
        vector<vector<pair<int,int>>> &adj,
        vector<bool> &online,
        long long k)
    {
        int n = online.size();

        // dist[i] = minimum recovery cost required to reach node i
        vector<long long> dist(n, LLONG_MAX);

        // Standard Dijkstra priority queue
        // {distance,node}
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0]=0;
        pq.push({0,0});

        while(!pq.empty())
        {
            auto [currDist,node]=pq.top();
            pq.pop();

            // Ignore outdated entries
            if(currDist>dist[node])
                continue;

            // Traverse neighbours
            for(auto &it:adj[node])
            {
                int next=it.first;
                int wt=it.second;

                // Offline nodes cannot be used
                if(!online[next])
                    continue;

                // Since we are checking minimum edge >= mid,
                // ignore smaller edges.
                if(wt<mid)
                    continue;

                if(dist[next]>currDist+wt)
                {
                    dist[next]=currDist+wt;
                    pq.push({dist[next],next});
                }
            }
        }

        // Reachable within budget?
        return dist[n-1]<=k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k)
    {

        int n=online.size();

        vector<vector<pair<int,int>>> adj(n);

        int mxEdge=0;

        // Build graph
        for(auto &e:edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
            mxEdge=max(mxEdge,e[2]);
        }

        //-----------------------------------------------------
        // Binary Search Answer
        //
        // low = smallest possible minimum edge
        // high = largest edge in graph
        //-----------------------------------------------------
        int low=0;
        int high=mxEdge;

        int ans=-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(possible(mid,adj,online,k))
            {
                // mid works
                ans=mid;

                // try larger answer
                low=mid+1;
            }
            else
            {
                // too large
                high=mid-1;
            }
        }

        return ans;
    }
};