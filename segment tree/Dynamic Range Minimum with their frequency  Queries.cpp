#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
 
 
struct node{
    int mini;
    int cnt;
    node(int m = 1e9,int c = 0){
     mini = m;
     cnt = c;
    }
};
ll n;
vector<ll> arr;
const int maxN = 2*1e5+5;
node t[4*maxN];

node combine(const node &a,const node &b){
    if(a.mini==b.mini){
        return node(a.mini,a.cnt+b.cnt);
    }
    else if(a.mini<b.mini){
        return a;
    }
    else{
        return b;
    }
}

void build(ll index,ll l,ll r){
  if(l==r){
    t[index] = node(arr[l],1);
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
        t[index] = node(val,1);
        arr[l] = val;
        return;
    }
    ll mid = (l+r)/2;
    update(index*2,l,mid,pos,val);
    update(index*2+1,mid+1,r,pos,val);
    t[index] = combine(t[index*2],t[index*2+1]); 
}
 
node query(ll index,ll l,ll r,ll lq,ll rq){
    if(l>rq||r<lq)return node();
    if(lq<=l&&r<=rq){ // lq<=l<=r<=rq   All these are already taken
        return t[index];
    }
    ll mid = (l+r)/2;
    return combine(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
}
 
void solve(){
ll q;
cin>>n>>q;
arr.resize(n+1);
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}
 
build(1,0,n-1); // we assume 1 is root node and responsible for 0 to n-1
 
while(q--){
    ll ch;
    cin>>ch;
    if(ch==1){
        ll x,v;
        cin>>x>>v;
        update(1,0,n-1,x-1,v);
    }
    else{
        ll l,r;
        cin>>l>>r;
        node x = query(1,0,n-1,l-1,r-1);
        cout<<x.mini<<" "<<x.cnt<<endl;
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
