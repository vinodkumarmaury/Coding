#include<bits/stdc++.h>
using namespace std;

struct UnionFind{

vector<int> rank,par;
int n, set_size;

UnionFind(int a){
    set_size = n = a;
    par.assign(n+1,0);
    rank.assign(n+1,1);
    for(int i = 1;i<=n;i++){
        par[i] = i;
    }
}

int find(int x){
    if(x==par[x])return x;
    else return par[x] = find(par[x]);
}

bool merge(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y)return false;
    if(rank[x]<rank[y]){
        rank[y]+=rank[x];
        par[x] = y;
    }
    else{
        rank[x]+=rank[y];
        par[y] = x;
    }
    set_size--;
    return true;
}

void reset(){
    set_size = n;
    for(int i = 1;i<=n;i++){
        par[i] = i;
    }
    rank.assign(n+1,1);
}

int size(){
    return set_size;
}

void print(){
    for(int i = 1;i<=n;i++){
    cout<<i<<"->"<<par[i]<<endl;
    }
}
int comp_size(int x){
return rank[find(x)];
}
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; // node and edges
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> g;
    for(int i = 0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g.push_back({w,{a,b}});
    }
    sort(g.begin(),g.end());
    UnionFind uf(n);

    long long cost = 0;
    vector<pair<int,int>> mst;
    for(int i = 0;i<m;i++){
        int u = g[i].second.first;
        int v = g[i].second.second;
        int w = g[i].first;
        if(uf.merge(u,v)){   // only take if they were in different components
            cost += w;
            mst.push_back({u,v});
        }
    }

    cout<<"MST cost = "<<cost<<"\n";
    cout<<"Edges in MST:\n";
    for(auto [u,v]:mst){
        cout<<u<<" "<<v<<"\n";
    }

}









