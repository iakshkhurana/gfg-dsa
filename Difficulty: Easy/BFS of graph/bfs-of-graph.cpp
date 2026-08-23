class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<bool>vis(n,false);
        vector<int>ans;
        queue<int>q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int nbr: adj[node]){
                if(!vis[nbr]){
                    vis[nbr]=true;
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
};