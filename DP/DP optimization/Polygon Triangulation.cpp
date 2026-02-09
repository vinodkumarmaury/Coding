#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
pair<int,int> p[101];

double sq(double x){
     return x*x;
}

double cost(int x,int y){
     double dist = sqrt(sq(p[x].first-p[y].first)+sq(p[x].second-p[y].second));
     return sin(dist);
}

void solve(){
cin>>n;
for(int i = 1;i<=n;i++){
     cin>>p[i].first>>p[i].second;
}
 vector<vector<double>> dp(n+1, vector<double>(n+1, 0.0));
for(int len = 3;len<=n;len++){
     for(int l = 1;l+len-1<=n;l++){
          int r = l+len-1;
          if(len==3){
               dp[l][r] = 0.0;
          }
          double ans = 1e9;
          for(int x = l+1;x<=r-1;x++){
               if(x==l+1){
                    ans = min(ans,cost(l+1,r)+dp[l+1][r]);
               }
               else if(x==r-1){
                    ans = min(ans,cost(l,r-1)+dp[l][r-1]);
               }
               else{
                    ans = min(ans,cost(l,x)+cost(x,r)+dp[l][x]+dp[x][r]);
               }
          }
          dp[l][r] = ans;
     }
}
cout << fixed << setprecision(6) << dp[1][n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}