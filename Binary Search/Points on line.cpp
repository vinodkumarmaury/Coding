#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'



void solve(){
ll n,d;
cin>>n>>d;
vector<ll> arr(n);
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}

ll ans = 0;
for(ll i = 0;i<n-2;i++){
ll index = upper_bound(arr.begin(),arr.end(),arr[i]+d)-arr.begin()-1;
if(index-i<=1)continue;
ll num = index-i;
ans+=(num*(num-1))/2;
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