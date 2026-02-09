#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
const ll inf = 1e18;

int n;
vector<ll> cost;
vector<vector<ll>> dp;
vector<ll> prefix;

ll rec(int l,int r){
    if(l>r)return inf;
    if(l==r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    ll ans = inf;
    ll total = prefix[r+1]-prefix[l];
    for(int mid = l;mid<r;mid++){
    ans = min(ans,total+rec(l,mid)+rec(mid+1,r));
    }
    return dp[l][r] = ans;
}

void solve(){
cin>>n;
cost.assign(n,0);
prefix.assign(n+1,0);
dp.assign(n+1,vector<ll>(n+1,-1));
for(int i = 0;i<n;i++){
    cin>>cost[i];
        prefix[i+1]+=prefix[i]+cost[i];
    }
    cout<<rec(0,n-1)<<endl;
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