#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

vector<double> prob;
int n;
vector<vector<double>> dp;

double rec(int level,int k){
    if(k<0)return 0;
    if(level==n)return k==0;
    if(dp[level][k]!=-1)return dp[level][k];
    double ans = rec(level+1,k)*(1-prob[level]);
    ans += rec(level+1,k-1)*prob[level];
    return dp[level][k] = ans;
}

void solve(){
cin>>n;
prob.assign(n,0);
for(int i = 0;i<n;i++){
    cin>>prob[i];
}
double ans = 0;
dp.assign(n+1,vector<double>(n+1,-1));
for(int i = n/2+1;i<=n;i++){
ans+=rec(0,i);
}
cout<<fixed<<setprecision(10)<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}