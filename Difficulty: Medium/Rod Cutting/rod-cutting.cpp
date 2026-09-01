class Solution {
  public:
    int f(int i, int L, vector<int>& price, vector<vector<int>>& dp){
        if(i==0)    return L*price[0];
        if(dp[i][L]!=-1)    return dp[i][L];
        int skip=f(i-1,L,price,dp);
        int take=(i+1<=L) ? price[i]+f(i,L-(i+1),price,dp):0;
        return dp[i][L]=max(skip,take);
    }
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};