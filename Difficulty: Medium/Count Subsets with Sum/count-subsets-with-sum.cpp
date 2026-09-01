class Solution {
  public:
    int memo(int i, int t, vector<int>& a, vector<vector<int>>& dp){
        if(i<0) return (t==0) ? 1 : 0;
        if(dp[i][t]!=-1)    return dp[i][t];
        int exclude = memo(i-1,t,a,dp);
        int include = (a[i]<=t) ? memo(i-1,t-a[i],a,dp) : 0;
        return dp[i][t] = exclude+include;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return memo(n-1,target,arr,dp);
    }
};