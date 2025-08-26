// https://cses.fi/problemset/task/1193

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
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
vector<vector<state>> par;

void bfs(state st){
    vis = vector<vector<int>>(n,vector<int>(m,0));
    dist = vector<vector<int>>(n,vector<int>(m,INF));
    par = vector<vector<state>>(n,vector<state>(m,make_pair(-1,-1)));

    queue<state> q;

    dist[st.F][st.S] = 0;
    q.push(st);

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
                par[v.F][v.S] = cur;
                q.push(v);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dist[i][j]<<"\t";
        //     }
        //     cout<<endl;
        // }cout<<endl;
    }
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    state st,en;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A'){
                st = {i,j};
            }else if(arr[i][j]=='B'){
                en = {i,j};
            }
        }
    }
    bfs(st);
    if(vis[en.F][en.S]){
        cout<<"YES\n";
        cout<<dist[en.F][en.S]<<endl;

        vector<state> path;
        state cur = en;
        while(cur != state({-1,-1})){
            path.push_back(cur);
            cur = par[cur.F][cur.S];
        }
        reverse(path.begin(),path.end());
        for(auto v:path){
            cout<<v.F<<" "<<v.S<<endl;
        }

    }else{
        cout<<"NO\n";
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