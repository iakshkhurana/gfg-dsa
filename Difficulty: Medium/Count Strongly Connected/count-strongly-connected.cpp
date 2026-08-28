class Solution {
    private:
      void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st) {
          vis[node] = 1;
          for (auto it : adj[node]) {
              if (!vis[it]) {
                  dfs(it, vis, adj, st);
              }
          }
          st.push(node);
      }
      void helperDFS(int node, vector<int> &vis, vector<vector<int>> &adjT) {
          vis[node] = 1;
          for (auto it : adjT[node]) {
              if (!vis[it]) {
                  helperDFS(it, vis, adjT);
              }
          }
      }
    public:
      int kosaraju(int V, vector<vector<int>> &edges) {
          vector<vector<int>> adj(V);
          for (auto &e : edges) {
              adj[e[0]].push_back(e[1]);
          }
          // step 1 : sort all edges according to finishing time
          vector<int> vis(V, 0);
          stack<int> st;
          for (int i = 0; i < V; i++) {
              if (!vis[i]) {
                  dfs(i, vis, adj, st);
              }
          }
          // step 2 : reverse the graph
          vector<vector<int>> adjT(V);
          for (int i = 0; i < V; i++) {
              vis[i] = 0;
              for (auto it : adj[i]) {
                  adjT[it].push_back(i);
              }
          }
          // step 3 : do dfs
          int count = 0;
          while (!st.empty()) {
              int node = st.top();
              st.pop();
              if (!vis[node]) {
                  count += 1;
                  helperDFS(node, vis, adjT);
              }
          }
          return count;
      }
  };