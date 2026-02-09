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

vector<int> t[4*N];

void build(int index,int l,int r){
    if(l==r){
        t[index].push_back(eul[l]);
        return;
    }
    int mid = (l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    merge(t[index*2].begin(), t[index*2].end(),
      t[index*2+1].begin(), t[index*2+1].end(),
      back_inserter(t[index]));
}



int query(int index,int l,int r,int lq,int rq,int x){
    if(rq<l||lq>r)return 0;
    if(lq<=l&&rq>=r){
        int cnt = t[index].end() - upper_bound(t[index].begin(), t[index].end(), x);
        return cnt;
    }
    int mid = (l+r)/2;
    return query(index*2,l,mid,lq,rq,x)+query(index*2+1,mid+1,r,lq,rq,x);
}

signed main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>values[i];
    for(int i = 2;i<=n;i++){
        int a;
        cin>>a;
        g[a].push_back(i);
        g[i].push_back(a);
    }


    dfs(1,0);
    build(1,1,2*n);
    
    for(int i = 1;i<=n;i++){
        cout<<query(1,1,2*n,in[i],out[i],values[i])<<endl;
    }

    return 0;
}



