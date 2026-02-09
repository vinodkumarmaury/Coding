#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

ll n;
const ll maxN = 2*1e5+5;
ll arr[maxN]; 
ll t[4*maxN]; // 4 times size of array size 





void update(ll index,ll l,ll r,ll lq,ll rq,ll val){
    if(l>rq||r<lq)return ;
    if(lq<=l&&r<=rq){ // lq<=l<=r<=rq   All these are already taken
        t[index]+=val;
        return;
    }
    ll mid = (l+r)/2;
    update(index*2,l,mid,lq,rq,val);
    update(index*2+1,mid+1,r,lq,rq,val);
}

ll query(ll index,ll l,ll r,ll pos,ll carry = 0){
    if(l==r){ // lq<=l<=r<=rq   All these are already taken
        return arr[l]+t[index]+carry;
    }
    ll mid = (l+r)/2;
    if(pos<=mid){
        return query(index*2,l,mid,pos,carry+t[index]);
    }
    else{
        return query(index*2+1,mid+1,r,pos,carry+t[index]);
    }
}

void solve(){
ll q;
cin>>n>>q;
for(ll i = 0;i<n;i++){
    cin>>arr[i];
}



while(q--){
    ll ch;
    cin>>ch;
    if(ch==1){
        ll a,b,u;
        cin>>a>>b>>u;
        update(1,0,n-1,a-1,b-1,u);
    }
    else{
        ll k;
        cin>>k;
        k--;
        cout<<query(1,0,n-1,k)<<endl;
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