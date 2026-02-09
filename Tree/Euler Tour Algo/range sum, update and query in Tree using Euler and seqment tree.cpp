#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+5;
vector<int> g[N];
int values[N];
int in[N],out[N];
int timer = 1;
int eul[2*N];
void dfs(int node,int pp){
    eul[timer] = values[node];
    in[node] = timer++;
    for(auto &v:g[node]){
        if(v!=pp){
            dfs(v,node);
        }
    }
    eul[timer] = 0;
    out[node] = timer++;
}

int t[4*N];

void build(int index,int l,int r){
    if(l==r){
        t[index] = eul[l];
        return;
    }
    int mid = (l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    t[index] = t[index*2]+t[index*2+1];
}

void update(int index,int l,int r,int id,int val){
    if(id<l||id>r)return;
    if(l==r){
        t[index] = val;
        return;
    }
    int mid = (l+r)/2;
    update(index*2,l,mid,id,val);
    update(index*2+1,mid+1,r,id,val);
    t[index] = t[index*2]+t[index*2+1];
}

int query(int index,int l,int r,int lq,int rq){
    if(rq<l||lq>r)return 0;
    if(lq<=l&&rq>=r){
        return t[index];
    }
    int mid = (l+r)/2;
    return query(index*2,l,mid,lq,rq)+query(index*2+1,mid+1,r,lq,rq);
}

signed main(){
    int n,q;
    cin>>n>>q;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1;i<=n;i++)cin>>values[i];

    dfs(1,0);
    build(1,1,2*n);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
          int x,y;
          cin>>x>>y;
          eul[in[x]] = y; 
          update(1,1,2*n,in[x],y);
          values[x] = y;
        }
        else{
          int x;
          cin>>x;
          cout<<query(1,1,2*n,in[x],out[x])<<endl;
        }
    }

    return 0;
}

// 7 4
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7
// 10 11 12 13 14 15 16
// 1 2 5
// 2 3
// 1 5 2
// 2 2
// output
// 43
// 20


