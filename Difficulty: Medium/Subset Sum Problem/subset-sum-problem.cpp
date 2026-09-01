class Solution {
  public:
    bool memo(int i, int t, vector<int>& a, vector<vector<int>>& dp){
        if(t==0)    return true;
        if(i==0)    return a[0]==t;
        if(dp[i][t]!=-1)    return dp[i][t];
        bool exclude=memo(i-1,t,a,dp);
        // tabhi chalega jab value badi hogi target se
        bool include= (a[i]<=t) ? memo(i-1,t-a[i],a,dp) : false;
        return dp[i][t] = (include || exclude);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        // sum is t
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return memo(n-1,sum,arr,dp);
    }
};