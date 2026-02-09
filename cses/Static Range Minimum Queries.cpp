#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

int n;
vector<int> arr;
vector<int> t;

void build(int index,int l,int r){
    if(l==r){
        t[index] = arr[l];
    }
    int mid = (l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    t[index] = min(t[index*2],t[index*2+1]);
}

int query(int index,int l,int r,int lq,int rq){
    if(l>rq||r<lq)return INT_MAX;
    if(lq<=l&&rq>=r){
        return t[index];
    }
    int mid = (l+r)/2;
    return min(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
}

void solve(){
int q;
cin>>n>>q;
arr.resize(n+1);
t.resize(4*n+4);
for(int i = 0;i<n;i++){
    cin>>arr[i];
}

build(1,0,n-1);
while(q--){
    int a,b;
    cin>>a>>b;
    a--,b--;
    int ans = query(1,0,n-1,a,b);
    cout<<ans<<endl;
}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}