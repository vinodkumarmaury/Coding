#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
#define S second
#define F first
using state = pair<int,pair<int,int>>;
const int inf = 1e9;

int n,m,bomb;
vector<vector<char>> mat;
vector<vector<vector<int>>> dist;
vector<vector<vector<int>>> num_path;
// vector<vector<state>>par;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};


bool isPossible(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m)return 1;
    return 0;
}

vector<state> neigbour(state curr){
    vector<state> ans;
    for(int k = 0;k<4;k++){
        int x = curr.S.F+dx[k];
        int y = curr.S.S+dy[k];
        if(isPossible(x,y)){
            if(mat[x][y]=='#'){
            ans.push_back({curr.F+1,{x,y}});
            }
            else{
                ans.push_back({curr.F,{x,y}});
            }
        }
    }
    return ans;
}

void bfs(state st){
  dist.assign(n,vector<vector<int>>(m,vector<int>(bomb+1,inf)));
    num_path.assign(n,vector<vector<int>>(m,vector<int>(bomb+1,0)));

queue<state> q;
q.push(st); //bomb,x,y
dist[st.S.F][st.S.S][st.F] = 0;
num_path[st.S.F][st.S.S][st.F] = 1;

while(!q.empty()){
    state curr = q.front();
    q.pop();
    if(curr.F>bomb)continue;
    for(auto &node:neigbour(curr)){
        if(dist[node.S.F][node.S.S][node.F]==inf){
            if(node.F<bomb){
            dist[node.S.F][node.S.S][node.F] = dist[curr.S.F][curr.S.S][curr.F]+1;
            num_path[node.S.F][node.S.S][node.F] = num_path[curr.S.F][curr.S.S][curr.F];
             q.push(node);
            }
        }
        else if( node.F<bomb && dist[node.S.F][node.S.S][node.F] == dist[curr.S.F][curr.S.S][curr.F]+1){
           num_path[node.S.F][node.S.S][node.F] += num_path[curr.S.F][curr.S.S][curr.F]; 
        }
    }
}

}

void solve(){
cin>>n>>m>>bomb;
mat.resize(n+1,vector<char>(m+1));
pair<int,int> st,end;
for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        cin>>mat[i][j];
        if(mat[i][j]=='S')st = {i,j};
        if(mat[i][j]=='E')end = {i,j};
    }
}
bfs({0,st}); // bomb,x,y



int minDist = inf;
    for(int k=0;k<=bomb;k++){
        minDist = min(minDist, dist[end.F][end.S][k]);
    }

    if(minDist==inf){
        cout<<0<<endl; // unreachable
        return;
    }

    int ans = 0;
    for(int k=0;k<=bomb;k++){
        if(dist[end.F][end.S][k]==minDist){
            ans += num_path[end.F][end.S][k];
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    cout<<dist[i][j][k]<<" ";
                }
                cout<<endl;
            }
        }
    }

    cout<<ans<<endl;

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