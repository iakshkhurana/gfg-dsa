class Solution {
    vector<vector<int>> adj;
    vector<bool> vis;

    vector<int> bfsHelper(int start) {
        queue<int> q;
        vector<int> comp;

        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            comp.push_back(node);

            for (auto nbr : adj[node]) {
                if (!vis[nbr]) {   
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return comp;
    }

  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        adj.assign(V, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);   // undirected
        }

        vis.assign(V, false);
        vector<vector<int>> components;

        // har unvisited node ek naye component ka start hai
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                components.push_back(bfsHelper(i));
            }
        }
        return components;
    }
};