#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

ll n,q;
const ll maxN = 2*1e5+5;
ll arr[maxN];

struct node{
ll sum,lazystart,lazyadd;
// bool isLazy  // we can use if we don't have specific no by which we can assign lazy mark 
node(){
    sum = 0;
    lazystart = 0;
    lazyadd = 0;
}
};

node t[4*maxN];

node merge(node a,node b){
    node ans;
    ans.sum = a.sum+b.sum;
    return ans;
}

void push(ll index,ll l,ll r){
    if(t[index].lazystart||t[index].lazyadd){
        ll sz = r-l+1;
        ll a = t[index].lazystart;
        ll d = t[index].lazyadd;
        t[index].sum += a*sz+d*(sz*(sz-1)/2);
        if(l!=r){
            ll mid = (r+l)/2;
            ll leftlen = mid-l+1;
            t[index*2].lazystart += a;
            t[index*2+1].lazystart += a+leftlen*d;
            t[index*2].lazyadd += d;
            t[index*2+1].lazyadd +=d;
        }
        t[index].lazystart = 0;
        t[index].lazyadd = 0;
    }
}

void build(ll index, ll l, ll r) {
    if (l == r) {
        t[index].sum = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(index*2, l, mid);
    build(index*2+1, mid+1, r);
    t[index] = merge(t[index*2], t[index*2+1]);
}

void update(ll index,ll l,ll r,ll lq,ll rq){
    push(index,l,r);
    if(lq>r||rq<l)return;
    if(lq<=l&&rq>=r){
    ll offset = l-lq+1;
    t[index].lazystart += offset;
    t[index].lazyadd +=1;
    push(index,l,r);
    return;
    }
    ll mid = (l+r)/2;
    update(index*2,l,mid,lq,rq);
    update(index*2+1,mid+1,r,lq,rq);
    t[index] = merge(t[index*2],t[index*2+1]);
}

node query(ll index,ll l,ll r,ll lq,ll rq){
    push(index,l,r);
    if(lq>r||rq<l)return node();
    if(lq<=l&&rq>=r){
    return t[index];
    }
    ll mid = (l+r)/2;
    return merge(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
}

void solve(){
cin>>n>>q;
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}

build(1,0,n-1);

while(q--){
    ll ch;
    cin>>ch;
    if(ch==1){
        ll a,b;
        cin>>a>>b;
        a--,b--;
        update(1,0,n-1,a,b);
    }
    else if(ch==2){
        ll a,b;
        cin>>a>>b;
        a--,b--;
        node ans = query(1,0,n-1,a,b);  
        cout<<ans.sum<<endl;
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