#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

ll n;
vector<ll> arr,t;



void build(ll index,ll l,ll r){
 if(l==r){
    t[index] = arr[l];
    return;
 } 
 ll mid = (l+r)/2;
 build(index*2,l,mid);
 build(index*2+1,mid+1,r);
 t[index] = max(t[index*2],t[index*2+1]);
}

void update(ll index,ll l,ll r,ll pos,ll val){
if(pos<l||pos>r)return;
if(l==r){
    t[index]-=val;
    return;
}
ll mid = (l+r)/2;
update(index*2,l,mid,pos,val);
update(index*2+1,mid+1,r,pos,val);
t[index] = max(t[index*2],t[index*2+1]);
}

ll query(ll index,ll l,ll r,ll req){
if(t[index]<req){
    return 0;
}
if(l==r){
    return l;
}
ll mid = (l+r)/2;
if(t[index*2]>=req){
   return query(index*2,l,mid,req);
}
else{
   return query(index*2+1,mid+1,r,req);
}
}

void solve(){
ll q;
cin>>n>>q;
arr.resize(n+1);
t.resize(4*n+4);
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}
build(1,0,n-1);

while(q--){
    ll req;
    cin>>req;
    ll ans = query(1,1,n,req);
    cout<<ans<<" ";
if(ans!=0){
    update(1,1,n,ans,req);
}
}
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