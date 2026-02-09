#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<vector<int>> g;
vector<int> vis;
vector<int> team;
bool isPossible;
void dfs(int node,int team_no){
    vis[node] = 1;
    team[node] = team_no;
    for(auto &v:g[node]){
        if(team[node]==team[v]){
            isPossible = false;
        }
        if(!vis[v]){
            dfs(v,3-team_no);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    team.assign(n+1);
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    isPossible = true;
    for(int i = 1;i<=n;i++){
      if(!vis[i]){
        dfs(i,1);
      }
    }
    if(!isPossible){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(auto &x:team){
        cout<<x<<" ";
    }
    return 0;
}

