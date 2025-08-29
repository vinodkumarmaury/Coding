#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
using state = pair<long long,pair<int,int>>; // { -dist , {i,j} }
#define F first
#define S second

int n,m;
vector<vector<long long>> mat;
vector<vector<long long>> dist;
vector<vector<int>> vis;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isValid(int x,int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void dijkstra(){
    priority_queue<state> pq;
    dist[0][0] = 0;
    pq.push({0,{0,0}});

    while(!pq.empty()){
        auto curr = pq.top(); pq.pop();
        int i = curr.S.F;
        int j = curr.S.S;
        if(vis[i][j]) continue;
        vis[i][j] = 1;
        long long d = -curr.F;

        for(int k=0;k<4;k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(!isValid(ni,nj)) continue;
            long long cost = mat[ni][nj]; // cost to move to neighbor
            if(dist[ni][nj] > d + cost){
                dist[ni][nj] = d + cost;
                pq.push({-dist[ni][nj],{ni,nj}});
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    mat.assign(n,vector<long long>(m));
    dist.assign(n,vector<long long>(m,inf));
    vis.assign(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    dijkstra();

    cout<<dist[n-1][m-1]<<endl; // minimum cost to reach bottom-right
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--) solve();
    return 0;
}
