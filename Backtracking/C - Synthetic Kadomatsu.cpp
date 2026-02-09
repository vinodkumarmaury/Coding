#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll n,a,b,c;
ll ans = LLONG_MAX;
vector<ll> arr;
void rec(ll level,ll suma,ll sumb,ll sumc,ll cost){
    if(level==n){
        if(suma==0||sumb==0||sumc==0){
        return;
        }
        ans = min(ans,cost+abs(suma-a)+abs(sumb-b)+abs(sumc-c));
        return;
    }
    rec(level+1,suma,sumb,sumc,cost);
    rec(level+1,suma+arr[level],sumb,sumc,cost+(suma>0?10:0));
    rec(level+1,suma,sumb+arr[level],sumc,cost+(sumb>0?10:0));
    rec(level+1,suma,sumb,sumc+arr[level],cost+(sumc>0?10:0));
}

void solve(){
cin>>n>>a>>b>>c;
arr.assign(n,0);
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}
rec(0,0,0,0,0);
cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}