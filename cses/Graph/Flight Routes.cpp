#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using state = pair<ll,ll>;
vector<vector<state>> g;
vector<vector<ll>> dist;
const ll inf = 1e18;
int n,m,k;


void dijkstra(){
    dist[1] = 0;
    priority_queue<state,vector<state>, greater<>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ll d = it.first;
        ll u = it.second;
        if(dist[u].size()>=k)continue;
        dist[u].push_back(d);
        for(auto &x:g[u]){
            ll v = x.second;
            ll w = x.first;
            dist[v] = dist[u]+w;
            pq.push({dist[v],v});
        }
    }
}

int main(){
    cin>>n>>m>>k;
    dist.assign(n+1);
    g.resize(n+1);
    for(int i = 0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({c,b});
    }
    dijkstra();
    cout<<dist[n]<<endl;
}