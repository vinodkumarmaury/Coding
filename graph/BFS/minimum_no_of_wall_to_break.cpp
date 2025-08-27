#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
using ll = long long;
using state = pair<int,int>;
const int mod = 1e9+7;
const int INF = 1e9;

int n,m;
vector<vector<char>> v;
vector<vector<int>> vis,dist;
vector<vector<state>> par;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

bool isPossibleMove(int x, int y){
  if(x>=0&&y>=0&&x<n&&y<m)return 1;
  return 0;
}

vector<pair<state,int>> neighbour(state curr){
  vector<pair<state,int>> ans;
  for(int k = 0;k<4;k++){
    int x = curr.F+dx[k];
    int y = curr.S+dy[k];
    if(isPossibleMove(x,y)){
      if(v[x][y]=='#'){
      ans.push_back({{x,y},1});
      }
      else{
       ans.push_back({{x,y},0});
      }
    }
  }
  return ans;
}

void BFS(state st){
deque<state> q;
q.push_front(st);
dist[st.F][st.S] = 0;
while(!q.empty()){
  state curr = q.front();
  q.pop_front();
   if(vis[curr.F][curr.S])continue;
        vis[curr.F][curr.S]=1;
  for(auto [x,c]:neighbour(curr)){
    if(dist[x.F][x.S]>dist[curr.F][curr.S]+c){
     dist[x.F][x.S] = dist[curr.F][curr.S]+c;
     par[x.F][x.S] = curr;
     if(c==1){
      q.push_back(x);
     }
     else{
      q.push_front(x);
     }
    }
  }
}
}

void solve(){
cin>>n>>m;
v.assign(n,vector<char>(m));
vis.assign(n,vector<int>(m));
dist.assign(n,vector<int>(m,INF));
par.assign(n,vector<state>(m,{-1,-1}));
state st,en;
for(int i = 0;i<n;i++){
  for(int j = 0;j<m;j++){
    cin>>v[i][j];
    if(v[i][j]=='S'){
      st = {i,j};
    }
    if(v[i][j]=='E'){
      en = {i,j};
    }
  }
}

BFS(st);
cout<<dist[en.F][en.S]<<endl;

// for(int i = 0;i<n;i++){
//   for(int j = 0;j<m;j++){
//     cout<<dist[i][j]<<" ";
//   }
//   cout<<endl;
// }

vector<state> path;

state curr = en;
while(curr!=make_pair(-1,-1)){
path.push_back(curr);
curr = par[curr.F][curr.S];
}

 reverse(path.begin(), path.end());

    cout << "Path:" << endl;
    for(auto p : path){
        cout << p.F << " " << p.S << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
      solve();
    }
    return 0;
}
