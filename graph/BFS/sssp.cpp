#include<bits/stdc++.h>
using namespace std;
const int INF = 100;
#define F first
#define S second

using state = int;

int n,a,b;
vector<int> arr;

vector<vector<pair<int,int>>> g;

vector<int> vis, dist;

void dijkstra(state st){
    vis = vector<int>(g.size());
    dist = vector<int>(g.size(),INF);

    priority_queue<pair<int,state>> q;

    dist[st]= 0;
    q.push({-0,st});

    while(!q.empty()){
        auto [dis,cur] = q.top();
        dis = -dis;
        q.pop();
        
        if(vis[cur])continue;
        vis[cur]=1;
        // process the node
        for(auto v:g[cur]){
            // relaxing edge.
            if(dist[v.F] > dis+v.S){
                dist[v.F] = dis+v.S;
                q.push({-dist[v.F],v.F});
            }
        }
    }
}

void solve(){
    cin>>n>>a>>b;
    arr.resize(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]];
    }
    int node_num = n;
    for(auto v:mp){
        mp[v.first]=node_num++;
    }
    g.resize(node_num);

    for(int i=0;i<n;i++){
        if(i-1>=0)g[i].push_back({i-1,a});
        if(i+1<n)g[i].push_back({i+1,a});
        g[i].push_back({mp[arr[i]],b});
        g[mp[arr[i]]].push_back({i,0});
    }    

    dijkstra(0);

    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}