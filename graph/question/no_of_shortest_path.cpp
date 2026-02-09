#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
#define S second
#define F first
using state = pair<int,int>;
const int inf = 1e9;

int n,m;
vector<vector<char>> mat;
vector<vector<int>> dist;
vector<vector<int>> num_path;
vector<vector<state>>par;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};


bool isPossible(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&mat[x][y]!='#')return 1;
    return 0;
}

vector<state> neigbour(state curr){
    vector<state> ans;
    for(int k = 0;k<4;k++){
        int x = curr.F+dx[k];
        int y = curr.S+dy[k];
        if(isPossible(x,y)){
            ans.push_back({x,y});
        }
    }
    return ans;
}

void bfs(state st){
dist.assign(n+1,vector<int>(m+1,inf));
num_path.assign(n+1,vector<int>(m+1,0));
par.assign(n+1,vector<state>(m+1,{-1,-1}));

queue<state> q;
q.push(st);
dist[st.F][st.S] = 0;
num_path[st.F][st.S] = 1;

while(!q.empty()){
    state curr = q.front();
    q.pop();
    for(auto &node:neigbour(curr)){
        if(dist[node.F][node.S]==inf){
            dist[node.F][node.S] = dist[curr.F][curr.S]+1;
            num_path[node.F][node.S] = num_path[curr.F][curr.S];
            par[node.F][node.S] = curr;
            q.push(node);
        }
        else if(dist[node.F][node.S] == dist[curr.F][curr.S]+1){
           num_path[node.F][node.S] += num_path[curr.F][curr.S]; 
        }
    }
}

}

void solve(){
cin>>n>>m;
mat.resize(n+1,vector<char>(m+1));
state st,end;
for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        cin>>mat[i][j];
        if(mat[i][j]=='S')st = {i,j};
        if(mat[i][j]=='E')end = {i,j};
    }
}
bfs(st);

for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        cout<<num_path[i][j]<<" ";
    }
    cout<<endl;
}

cout<<num_path[end.F][end.S]<<" "<<dist[end.F][end.S];

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}