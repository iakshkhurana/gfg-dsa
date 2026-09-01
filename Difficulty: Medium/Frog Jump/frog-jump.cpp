class Solution {
  public:
    int f(int i, vector<int>& h, vector<int>& dp) {
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];
        int one = f(i-1, h, dp) + abs(h[i] - h[i-1]);
        int two = (i > 1) ? f(i-2, h, dp) + abs(h[i] - h[i-2]) : INT_MAX;
        return dp[i] = min(one, two);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return f(n-1, height, dp);     // last stone tak ka min cost
    }
};