#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

ll n,m;
bool check(ll mid,ll brr[],ll arr[]){
    ll i = 0,j = 0;
    while(i<n&&j<m){
        while(i<n&&abs(arr[i]-brr[j])<=mid){
            i++;
        }
        j++;
    }
    return i==n;
}

void solve(){
cin>>n>>m;
ll arr[n];
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}

ll brr[m];
for(ll i = 0;i<m;i++){
    cin>>brr[i];
}

ll low = 0;
ll high = abs(min(arr[0],brr[0])-max(arr[n-1],brr[m-1]));
ll ans = high;

while(low<=high){
    ll mid = low+(high-low)/2;
    if(check(mid,brr,arr)){
        high = mid-1;
        ans = mid;
    }
    else{
        low = mid+1;
    }
}
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