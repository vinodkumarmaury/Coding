#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll n,m,k;


bool check(ll mid){
ll ans = 0;
for(ll i = 1;i<=n;i++){
    ans+=min(m,mid/i);
}
return ans >= k;
}

void solve(){
cin>>n>>m>>k;
ll low = 1,high = n*m;
ll ans = high/2;

while(low<=high){
    ll mid = low+(high-low)/2;
    if(check(mid)){
        ans = mid;
        high = mid-1;
    }
    else{
        low = mid+1;
    }
}
cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}