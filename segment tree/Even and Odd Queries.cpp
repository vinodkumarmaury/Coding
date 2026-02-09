#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
 
 
struct node{
    int odd,even;
    node(int m = 0, int o = 0, int e = 0) {
        odd = o;
        even = e;
        if(m != 0) {
            if(m % 2 == 0) {
                odd = 0;
                even = 1;
            } else {
                odd = 1;
                even = 0;
            }
        }
    }
};
ll n;
vector<ll> arr;
const int maxN = 1e5+5;
node t[4*maxN];

node combine(const node &a,const node &b){
    return node(0,a.odd+b.odd,a.even+b.even);
}

void build(ll index,ll l,ll r){
  if(l==r){
    t[index] = node(arr[l]);
    return;
  }
  ll mid = (l+r)/2;
  build(index*2,l,mid);
  build(index*2+1,mid+1,r);
  t[index] = combine(t[index*2],t[index*2+1]);
}
 
 
void update(ll index,ll l,ll r,ll pos,ll val){
    if(pos<l||pos>r){
        return;
    }
    if(l==r){
        t[index] = node(val);
        arr[l] = val;
        return;
    }
    ll mid = (l+r)/2;
    update(index*2,l,mid,pos,val);
    update(index*2+1,mid+1,r,pos,val);
    t[index] = combine(t[index*2],t[index*2+1]); 
}
 
node query(ll index,ll l,ll r,ll lq,ll rq){
    if(l>rq||r<lq)return node(0,0,0);
    if(lq<=l&&r<=rq){ // lq<=l<=r<=rq   All these are already taken
        return t[index];
    }
    ll mid = (l+r)/2;
    return combine(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
}
 
void solve(){
cin>>n;
arr.resize(n+1);
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}
 
build(1,0,n-1); // we assume 1 is root node and responsible for 0 to n-1
 int q;
 cin>>q;
while(q--){
    ll ch;
    cin>>ch;
    
    if(ch==0){
        ll x,v;
        cin>>x>>v;
        update(1,0,n-1,x-1,v);
    }
    else if(ch==1){
        ll l,r;
        cin>>l>>r;
        l--,r--;
        node x = query(1,0,n-1,l,r);
        cout<<x.even<<endl;
    }
    else{
       ll l,r;
       cin>>l>>r;
       l--,r--;
       node x = query(1,0,n-1,l,r);
       cout<<x.odd<<endl; 
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
