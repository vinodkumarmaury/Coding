#include<bits/stdc++.h>
using namespace std;
const int INF = 100;
#define F first
#define S second

using state = pair<pair<int,int>,int>;

int n,m,k;
vector<string> arr;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

bool inside(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)return 1;
    return 0;
}

vector<state> neighbour(state s){
    vector<state> ans;
    for(int dir=0;dir<4;dir++){
        pair<int,int> temp = make_pair(s.F.F+dx[dir],s.F.S+dy[dir]);
        if(inside(temp.F,temp.S)){
            if(arr[temp.F][temp.S]=='#' && s.S<k)
                ans.push_back({temp,s.S+1});
            else if(arr[temp.F][temp.S]!='#')
                ans.push_back({temp,s.S});
        }
    }
    return ans;
}

vector<vector<vector<int>>> vis, dist;

void bfs(state st){
    vis = vector<vector<vector<int>>>(n,
                    vector<vector<int>>(m,
                            vector<int>(k+1,
                                0
                            )));
    dist = vector<vector<vector<int>>>(n,
                    vector<vector<int>>(m,
                            vector<int>(k+1,
                                INF
                            )));

    queue<state> q;

    dist[st.F.F][st.F.S][st.S] = 0;
    q.push(st);

    while(!q.empty()){
        state cur = q.front();
        q.pop();
        
        if(vis[cur.F.F][cur.F.S][cur.S])continue;
        vis[cur.F.F][cur.F.S][cur.S]=1;
        // process the node
        for(auto v:neighbour(cur)){
            // relaxing edge.
            if(dist[v.F.F][v.F.S][v.S] > 
                dist[cur.F.F][cur.F.S][cur.S]+1){
                dist[v.F.F][v.F.S][v.S] = 
                    dist[cur.F.F][cur.F.S][cur.S]+1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    k=n+m-2;
    arr.resize(n);
    pair<int,int> st,en;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S'){
                st = {i,j};
            }else if(arr[i][j]=='E'){
                en = {i,j};
            }
        }
    }
    bfs({st,0});
    int minpath = INF;

    for(int i=0;i<=n*m;i++){
        if(i<=n+m-2) minpath = min(minpath,dist[en.F][en.S][i]);
        cout<< i<<" : "<<minpath<<endl;
    }
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