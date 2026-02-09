#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
 
ll n,q;
const ll maxN = 2*1e5+5;
ll arr[maxN];
 
struct node{
ll sum,setlazy,addlazy;
// bool issetlazy  // we can use if we don't have specific no by which we can assign setlazy mark 
node(){
    sum = 0;
    setlazy = 0;
    addlazy = 0;
}
};
 
node t[4*maxN];
 
node merge(node a,node b){
    node ans;
    ans.sum = a.sum+b.sum;
    return ans;
}
 
void push(ll index,ll l,ll r){
    if(t[index].setlazy){
        t[index].sum = t[index].setlazy*(r-l+1);
        if(l!=r){
            t[index*2].setlazy = t[index].setlazy;
            t[index*2+1].setlazy = t[index].setlazy;
            t[index*2].addlazy = 0;
            t[index*2+1].addlazy = 0;
        }
        t[index].setlazy = 0;
    }
    if(t[index].addlazy!=0){
        t[index].sum+=t[index].addlazy*(r-l+1);
        if(l!=r){
            t[index*2].addlazy += t[index].addlazy;
            t[index*2+1].addlazy += t[index].addlazy;
        }
        t[index].addlazy = 0;
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
 
void update(ll index,ll l,ll r,ll lq,ll rq,ll val,int ch){
    push(index,l,r);
    if(lq>r||rq<l)return;
    if(lq<=l&&rq>=r){
        if(ch==2){
        t[index].setlazy = val;
        }
        else{
            t[index].addlazy = val;
        }
    push(index,l,r);
    return;
    }
    ll mid = (l+r)/2;
    update(index*2,l,mid,lq,rq,val,ch);
    update(index*2+1,mid+1,r,lq,rq,val,ch);
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
        ll a,b,x;
        cin>>a>>b>>x;
        a--,b--;
        update(1,0,n-1,a,b,x,ch);
    }
    else if(ch==2){
        ll a,b,x;
        cin>>a>>b>>x;
        a--,b--;
        update(1,0,n-1,a,b,x,ch);
    }
    else{
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