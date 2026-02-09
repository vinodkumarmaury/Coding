#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

ll n;
ll arr[100100]; 
ll t[400400]; // 4 times size of array size 


void build(ll index,ll l,ll r){
  if(l==r){
    t[index] = 0;
    return;
  }
  ll mid = (l+r)/2;
  build(index*2,l,mid);
  build(index*2+1,mid+1,r);
  t[index] = t[index*2]+t[index*2+1];
}


void update(ll index,ll l,ll r,ll pos,ll val){
    if(pos<l||pos>r){
        return;
    }
    if(l==r){
        t[index] += val;
        return;
    }
    ll mid = (l+r)/2;
    update(index*2,l,mid,pos,val);
    update(index*2+1,mid+1,r,pos,val);
    t[index] = t[index*2]+t[index*2+1]; 
}

ll query(ll index,ll l,ll r,ll pos, ll carry = 0){
    if(l==r){
        return t[index]+carry;
    }
    ll mid = (l+r)/2;
    if(pos<=mid)
    return query(index*2,l,mid,pos,t[index]+carry);
    else
    return query(index*2+1,mid+1,r,pos,t[index]+carry);
}

void solve(){
  ll q;
cin>>n>>q;
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}

build(1,0,n-1); // we assume 1 is root node and responsible for 0 to n-1

while(q--){
    ll ch;
    cin>>ch;
    if(ch==1){
        ll a,b,u;
        cin>>a>>b>>u;
        a--,b--;
        update(1,0,n-1,a,u);
        if(b+1<n)
        update(1,0,n-1,b+1,-u);
    }
    else{
        ll k;
        cin>>k;
        k--;
       cout<<query(1,0,n-1,k)+arr[k]<<endl;
    }
}
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