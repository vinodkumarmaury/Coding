class Solution {
  public:
    
    bool rec(int x,int y,vector<vector<int>> &dp){
        if(x==0&&y==0)return 0;
    
        if(dp[x][y]!=-1)return dp[x][y];
        int win = 0;
        for(int i = 1;i<=x;i++){
            if(rec(x-i,y,dp)==0){
                win = 1;
            }
        }
         for(int i = 1;i<=y;i++){
            if(rec(x,y-i,dp)==0){
                win = 1;
            }
        }
         for(int i = 1;i<=min(x,y);i++){
            if(rec(x-i,y-i,dp)==0){
                win = 1;
            }
        }
        return dp[x][y] = win;
    }
    
    bool game(int a, int b) {
        vector<vector<int>> dp;
        dp.assign(a+1,vector<int>(b+1,-1));
        return rec(a,b,dp);
    }
};
