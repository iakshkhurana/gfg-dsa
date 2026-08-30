class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Build adjacency list: adj[u] = {v, wt}
        vector<vector<pair<int,int>>> adj(V);
        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int,int>,
            vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> vis(V, 0);
        pq.push({0, 0});   // {wt, node}
        int sum = 0;

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;

            for (auto &[adjNode, edW] : adj[node]) {
                if (vis[adjNode] == 0) {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};