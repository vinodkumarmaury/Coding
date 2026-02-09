#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'


// You are given N wooden boards with lengths represented by the array A = {A₁, A₂, …, Aₙ}, and there are k painters available to paint them. Each painter takes exactly 1 unit of time to paint 1 unit length of a board. The task is to determine the minimum time required to paint all the boards under two important conditions — first, no two painters can share the same board, meaning a single board must be painted entirely by one painter only; and second, **each painter can only paint contiguous boards, i.e., if a painter paints board 1 and board 3 but skips board 2 in between, it is considered invalid. The challenge is to distribute the boards among the painters so that the work finishes in the least possible time while satisfying both these constraints.


ll n;
bool check(ll mid,ll arr[],ll k){
ll i = 0;
while(i<n&&k){
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
ll k;
cin>>n>>k; // number og board and no of paller
ll arr[n];
ll sum = 0;
for(ll i = 0;i<n;i++){
    cin>>arr[i];
    sum+=arr[i];
}
ll ans = sum,high = sum,low = 0;
while(low<=high){
    ll mid = low+(high-low)/2;
    if(check(mid,arr,k)){
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
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}