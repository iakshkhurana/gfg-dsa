class Solution {
  public:
    vector<int>vis, result;
    vector<vector<int>> g;
    void solve(int node){
        vis[node]=1;
        result.push_back(node);
        for(int nb:g[node]){
            if(!vis[nb]){
                solve(nb);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        // adj list given
        // visited array lelo
        // starting node ko 0 hi lelo
        g=adj;
        vis.assign(g.size(),0);
        result.clear();
        solve(0);
        return result;
    }
};