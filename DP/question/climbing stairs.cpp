class Solution {
public:

    int rec(int level,int n,vector<int> &dp){
        if(level==n)return 1;
        if(dp[level]!=-1){
            return dp[level];
        }
        int ans = 0;
        if(level+1<=n){
            ans+=rec(level+1,n,dp);
        }
        if(level+2<=n){
            ans+=rec(level+2,n,dp);
        }
        return  dp[level] = ans;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return rec(0,n,dp);
    }
};