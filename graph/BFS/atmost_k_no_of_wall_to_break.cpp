
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
using ll = long long;
using state = pair<pair<int,int>,int>;
const int mod = 1e9+7;
const int INF = 1e;

int n,m,k;
vector<vector<char>> v;
vector<vector<vector<int>>> vis, dist;
vector<vector<vector<state>>> par;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

bool isPossibleMove(int x, int y){
  if(x>=0&&y>=0&&x<n&&y<m)return 1;
  return 0;
}

vector<state> neighbour(state curr){
  vector<state> ans;
  for(int dir = 0;dir<4;dir++){
    int x = curr.F.F+dx[dir];
    int y = curr.F.S+dy[dir];
    if(isPossibleMove(x,y)){
      if(v[x][y]=='#'&&curr.S<k){
      ans.push_back({{x,y},curr.S+1}); 
      }
      else{
       ans.push_back({{x,y},curr.S});
      }
    }
  }
  return ans;
}

void BFS(state st){
queue<state> q;
q.push(st);
dist[st.F.F][st.F.S][st.S] = 0;
while(!q.empty()){
  state curr = q.front();
  q.pop();
   if(vis[curr.F.F][curr.F.S][curr.S])continue;
        vis[curr.F.F][curr.F.S][curr.S]=1;
  for(auto &x:neighbour(curr)){
    if(dist[x.F.F][x.F.S][x.S]>dist[curr.F.F][curr.F.S][curr.S]+1){
     dist[x.F.F][x.F.S][x.S] = dist[curr.F.F][curr.F.S][curr.S]+1;
     par[x.F.F][x.F.S][x.S] = curr;
     q.push(x);
    }
  }
}
}

void solve(){
cin>>n>>m>>k;
v.assign(n,vector<char>(m));
vis.assign(n, vector<vector<int>>(m, vector<int>(k+1, 0)));
dist.assign(n, vector<vector<int>>(m, vector<int>(k+1, INF)));
par.assign(n, vector<vector<state>>(m, vector<state>(k+1, {{-1,-1},-1})));
pair<int,int> st,en;
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

BFS({st,0});

int minPath = INF;

for(int i = 0;i<k;i++){
  cout<<"path for k value of "<<i<<endl;
for(int j = 0;j<n;j++){
  for(int z = 0;z<m;z++){
    cout<<dist[j][z][i]<<" ";
  }
  cout<<endl;
}
}


int bestK = 0;
int minDist = INF;
for(int kk = 0; kk <= k; kk++){
    if(dist[en.F][en.S][kk] < minDist){
        minDist = dist[en.F][en.S][kk];
        bestK = kk;
    }
}

vector<state> path;
state curr = {en, bestK};  

while(curr != make_pair(make_pair(-1,-1), -1)){
    path.push_back(curr);
    curr = par[curr.F.F][curr.F.S][curr.S];  
}

reverse(path.begin(), path.end());

cout << "Path:" << endl;
for(auto p : path){
    cout << p.F.F << " " << p.F.S << " (k=" << p.S << ")" << endl;

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
