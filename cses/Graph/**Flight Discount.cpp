#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using state = pair<ll,ll>;
const ll inf = 1e18;

int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<state>> g(n+1);
    for(ll i = 0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    vector<vector<ll>> dist(n+1,vector<ll>(2,inf));
    priority_queue<pair<ll,state>,vector<pair<ll,state>>,greater<>>pq;
    pq.push({0,{1,0}}); // weight,node,used.  used = 1, not used=1
    dist[1][0] = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ll used = it.second.second;
        ll node = it.second.first;
        ll cost = it.first;
        if(cost!=dist[node][used])continue;
        for(auto &temp:g[node]){
            ll v = temp.first;
            ll w = temp.second;
            if(used==0){
             // without using coupon
              if(dist[v][0]>cost+w){
                dist[v][0] = cost+w;
                pq.push({dist[v][0],{v,0}});
              }
              // by using coupon
              if(dist[v][1]>cost+w/2){
                 dist[v][1] = cost+w/2;
                 pq.push({dist[v][0],{v,1}});
              }
            }
            else{
             if(dist[v][1]>cost+w){
                dist[v][1] = cost+w;
             }
            }
        }
    }
    cout<<dist[n][1]<<endl;
}