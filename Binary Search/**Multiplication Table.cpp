#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

bool check(ll mid,ll n){
ll ans = 0;
for(ll i = 1;i<=n;i++){
    ans+=min(n,mid/i);
}
return ans >= ((n * n + 1) / 2);
}

void solve(){
ll n;
cin>>n;
ll low = 1,high = n*n;
ll ans = high/2;

while(low<=high){
    ll mid = low+(high-low)/2;
    if(check(mid,n)){
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