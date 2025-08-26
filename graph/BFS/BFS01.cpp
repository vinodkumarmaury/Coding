#include<bits/stdc++.h>
using namespace std;
const int INF = 100;
#define F first
#define S second

using state = pair<int,int>;

int n,m;
vector<string> arr;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

bool inside(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)return 1;
    return 0;
}

vector<pair<state,int>> neighbour(state s){
    vector<pair<state,int>> ans;
    for(int k=0;k<4;k++){
        state temp = make_pair(s.F+dx[k],s.S+dy[k]);
        if(inside(temp.F,temp.S)){
            if(arr[temp.F][temp.S]=='#')
                ans.push_back({temp,1});
            else
                ans.push_back({temp,0});
        }
    }
    return ans;
}

vector<vector<int>> vis, dist;

void bfs01(state st){
    vis = vector<vector<int>>(n,vector<int>(m,0));
    dist = vector<vector<int>>(n,vector<int>(m,INF));

    deque<state> q;

    dist[st.F][st.S] = 0;
    q.push_front(st);

    while(!q.empty()){
        state cur = q.front();
        q.pop_front();
        
        if(vis[cur.F][cur.S])continue;
        vis[cur.F][cur.S]=1;
        // process the node
        for(auto [v,c]:neighbour(cur)){
            // relaxing edge.
            if(dist[v.F][v.S] > dist[cur.F][cur.S]+c){
                dist[v.F][v.S] = dist[cur.F][cur.S]+c;
                if(c==1)
                    q.push_back(v);
                else
                    q.push_front(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    state st,en;
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
    bfs01(st);
    cout<<dist[en.F][en.S]<<endl;
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