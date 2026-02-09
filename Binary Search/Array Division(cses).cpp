#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'


bool check(ll mid,ll k,ll n,ll arr[]){
    ll i = 0;
    while(i<n){
        ll num = mid;
        while(i<n&&num-arr[i]>=0){
            num = num-arr[i];
            i++;
        }
        k--;
        if(k<0)return false;
    }
    if(i!=n)return false;
    return true;
}

void solve(){
ll n,k;
cin>>n>>k;
ll arr[n];
ll sum = 0;
for(ll i = 0;i<n;i++){
    cin>>arr[i];
    sum+=arr[i];
}

ll low = 0,high = sum,ans = sum;

while(low<=high){
    ll mid = low+(high-low)/2;
    if(check(mid,k,n,arr)){
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