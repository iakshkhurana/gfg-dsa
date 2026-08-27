// class Solution {
//   public:
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
//         // step 1 is to compute adjacency list
//         vector<vector<int>> adj(V);
//         for(auto& e: edges){
//             adj[e[0]].push_back(e[1]);
//         }
//         // step 2 is to compute the indegree
//         vector<int> indegree(V,0);
//         for(int i=0;i<V;i++){
//             for(auto it:adj[i]){
//                 indegree[it]++;
//             }
//         }
//         // step 3 is to do the main thing jisme 0 indegree wala kaam krna h
//         queue<int>q;
//         for(int i=0;i<V;i++){
//             if(indegree[i]==0)  q.push(i);
//         }
//         // step 4 is to do bfs
//         vector<int>topo;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             topo.push_back(node);
//             for(auto it: adj[node]){
//                 if(--indegree[it]==0)   q.push(it);
//             }
//         }
//         return topo;
//     }
// };

class Solution {
  private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);   // saare neighbours ho gaye, ab push
    }

  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // 1. adjacency list (directed: u -> v)
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        // 2. DFS from every unvisited node
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // 3. stack se nikaalo
        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};