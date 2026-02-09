#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

ll n,m;
vector<ll> arr;
const int maxN = 2*1e5+5;
struct Node{
    ll sum,prefix,suffix,ans;
    Node(ll v = 0){
        sum = v;
        ans = prefix = suffix = max(0LL,v); 
    }
};

Node t[4*maxN];

Node combine(Node &L, Node &R){
    Node res;
    res.sum = L.sum+R.sum;
    res.prefix = max(L.prefix,L.sum+R.prefix);
    res.suffix = max(R.suffix,R.sum+L.suffix);
    res.ans = max({L.ans,R.ans,L.suffix+R.prefix});
    return res;
}

void build(ll index,ll l,ll r){
    if(l==r){
      t[index] = Node(arr[l]);
      return;
    }
    ll mid = (l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    t[index] = combine(t[index*2],t[index*2+1]);
}

void update(ll index,ll l,ll r,ll pos,ll val){
    if(l>pos||pos>r)return;
    if(l==r){
        t[index] = Node(val);
        arr[l] = val;
    return;
    }
    ll mid = (l+r)/2;
    if(pos<=mid){
    update(index*2,l,mid,pos,val);
    }
    else{
        update(index*2+1,mid+1,r,pos,val);
    }
   t[index] = combine(t[index*2],t[index*2+1]);
}

Node query(ll index,ll l,ll r,ll lq,ll rq){
    if(l>rq||r<lq)return Node();
    if(lq<=l&&rq>=r){
        return t[index];
    }
    ll mid = (l+r)/2;
    Node x = query(index*2,l,mid,lq,rq);
    Node y = query(index*2+1,mid+1,r,lq,rq);
    return combine(x,y);
}

void solve(){
cin>>n>>m;
arr.resize(n+1);
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}
build(1,0,n-1);

while(m--){
   ll k,x;
   cin>>k>>x;
   k--;
   update(1,0,n-1,k,x);
   Node ans = query(1,0,n-1,0,n-1);
   cout<<ans.ans<<endl;
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