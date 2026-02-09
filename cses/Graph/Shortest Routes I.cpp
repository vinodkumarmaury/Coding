#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
using state = pair<ll,ll>;
vector<ll> dist;
vector<int> vis;
ll n,m;
vector<vector<state>> g;

void dijkstra(){
    priority_queue<state,vector<state>,greater<state>> pq;
    pq.push({0,1});
    dist[1] = 0;
  
    while(!pq.empty()){
        state node = pq.top();
        pq.pop();
        if(vis[node.second])continue;
        vis[node.second] = 1;
        for(auto &v:g[node.second]){
            if(dist[v.second]>dist[node.second]+v.first){
              dist[v.second] = dist[node.second]+v.first;
                pq.push({dist[v.second],v.second});
                
            }
        }
    }
}

void solve(){
cin>>n>>m;
vis.assign(n+1,0);
dist.assign(n+1,1e18);
g.assign(n+1,{});

for(ll i = 0;i<m;i++){
ll a,b,c;
cin>>a>>b>>c;
g[a].push_back({c,b});
}
dijkstra();

for(ll i = 1;i<=n;i++){
  cout<<dist[i]<<" ";
}
cout<<endl;
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