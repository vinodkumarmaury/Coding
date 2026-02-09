#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

bool check(ll mid,ll t,ll arr[],ll n){
    ll count = 0;
    for(ll i = 0;i<n;i++){
        count+=(mid/arr[i]);
    }
    return count>=t;
}

void solve(){
ll n,t;
cin>>n>>t;
ll arr[n];
ll maxi = LLONG_MIN,mini = LLONG_MAX;
for(ll i = 0;i<n;i++){
    cin>>arr[i];
    mini = min(mini,arr[i]);
}
ll low = 0,high = mini*t;
ll ans = high;
while(low<=high){
    ll mid = low+(high-low)/2;
    if(check(mid,t,arr,n)){
        high = mid-1;
        ans = mid;
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