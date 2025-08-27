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
    if(x>=0 && x<n && y>=0 && y<m && arr[x][y]!='#')return 1;
    return 0;
}

vector<state> neighbour(state s){
    vector<state> ans;
    for(int k=0;k<4;k++){
        state temp = make_pair(s.F+dx[k],s.S+dy[k]);
        if(inside(temp.F,temp.S)){
            ans.push_back(temp);
        }
    }
    return ans;
}

vector<vector<int>> vis, dist;
// auxialiary tables.
vector<vector<state>> par,origin;
vector<vector<int>> num_path;

void bfs(vector<state> allst){
    vis = vector<vector<int>>(n,vector<int>(m,0));
    dist = vector<vector<int>>(n,vector<int>(m,INF));

    // initialize auxilary table
    num_path = vector<vector<int>>(n,vector<int>(m,0));
    par = origin = vector<vector<state>>(n,vector<state>(m,{-1,-1}));

    queue<state> q;

    for(auto st:allst){
        dist[st.F][st.S] = 0;
        q.push(st);
        // auxiliary for the origins.
        par[st.F][st.S] = {-1,-1};
        origin[st.F][st.S] = st;
        num_path[st.F][st.S] = 1;
    }

    while(!q.empty()){
        state cur = q.front();
        q.pop();
        
        if(vis[cur.F][cur.S])continue;
        vis[cur.F][cur.S]=1;
        // process the node
        for(auto v:neighbour(cur)){
            // relaxing edge.
            if(dist[v.F][v.S] > dist[cur.F][cur.S]+1){
                dist[v.F][v.S] = dist[cur.F][cur.S]+1;
                q.push(v);
                // propagate auxiliary data.
                par[v.F][v.S] = cur;
                origin[v.F][v.S] = origin[cur.F][cur.S];
                num_path[v.F][v.S] += num_path[cur.F][cur.S];
            }else if(dist[v.F][v.S] == dist[cur.F][cur.S]+1){
                num_path[v.F][v.S] += num_path[cur.F][cur.S];
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    vector<state> st,en;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S'){
                st.push_back({i,j});
            }else if(arr[i][j]=='E'){
                en.push_back({i,j});
            }
        }
    }
    bfs(en);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
    int min_dist = INF;
    for(auto [x,y]:st){
        cout<<x<<","<<y<<":"<<dist[x][y]<<" "<<origin[x][y].F<<","<<origin[x][y].S<<" "<<num_path[x][y]<<endl;

        min_dist = min(dist[x][y],min_dist);
    }

    int tot_paths = 0;
    // find the total closest S , E pair paths.
    for(auto [x,y]:st){
        if(dist[x][y]==min_dist){
            tot_paths+= num_path[x][y];
        }
    }
    cout<<tot_paths<<endl;

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