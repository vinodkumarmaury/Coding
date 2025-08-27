#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define F first
#define S second
int const mod =  1e+7;
int const INF = 1e9;
using state = pair<int,int>;
#define endl "\n"
 
vector<string> s;
int n,m;
queue<state> q;
vector<vector<int>> vis;
vector<vector<int>> dist;
vector<vector<state>> par;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
 
bool isInside(int x,int y){
  if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]!='#')return 1;
  return 0;
}
 
vector<state> neighbour(state curr){
  vector<state> ans;
  for(int k = 0;k<4;k++){
    int x = curr.F+dx[k];
    int y = curr.S+dy[k];
    if(isInside(x,y)){
      ans.push_back({x,y});
    }
  }
  return ans;
}
 
void BFS(state st){
dist[st.F][st.S] = 0;
q.push(st);
while(!q.empty()){
  state curr = q.front();
  q.pop();
  vis[curr.F][curr.S] = 1;  
  // We don't need because we will never go back to previous node because it's never be lesser 
  
  for(auto &v:neighbour(curr)){
    if(dist[v.F][v.S]>dist[curr.F][curr.S]+1){
      dist[v.F][v.S] = dist[curr.F][curr.S]+1;
      q.push(v);
      par[v.F][v.S] = curr;
    }
  }
}
}
 
void solve(){
cin>>n>>m;
s.resize(n);
vis.resize(n,vector<int>(m,0));
dist.resize(n,vector<int>(m,INF));
par.resize(n,vector<state>(m,{-1,-1}));
state st,end;
for(int i = 0;i<n;i++){
  cin>>s[i];
  for(int j = 0;j<m;j++){
    if(s[i][j]=='A'){
      st = {i,j};
    }
    else if(s[i][j]=='B'){
      end = {i,j};
    }
  }
}
 
BFS(st);
 
// for(int i = 0;i<n;i++){
//   for(int j = 0;j<m;j++){
//     cout<<dist[i][j]<<"\t";
//   }
//   cout<<endl;
// }
 
vector<state> path;
 
state curr = end;
// path.push_back(curr);
state p = {-1,-1};
  while(curr!=p){
    // cout<<curr.F<<" "<<curr.S<<" ";
    path.push_back(curr);
    curr = par[curr.F][curr.S];
    // cout<<endl;
  }
 
reverse(path.begin(),path.end());
// for(auto &v:path){
//   cout<<v.F<<" "<<v.S<<" ";
//   cout<<endl;
// }
 
string res;
 
state start = path[0];
 
for(int i = 1;i<(int)path.size();i++){
  state temp = path[i];
  if(temp.F==start.F){
    if(temp.S>start.S){
      res+="R";
    }
    else{
      res+="L";
    }
  }
  else{
    if(temp.F>start.F){
      res+="D";
    }
    else{
      res+="U";
    }
  }
  start = temp;
}
 
 
if(vis[end.F][end.S]){
  cout<<"YES"<<endl;
  cout<<dist[end.F][end.S]<<endl;
  cout<<res<<endl;
}
else{
  cout<<"NO"<<endl;
}
 
}
 
 
int main() 
{
    int t = 1;
    while(t--){
      solve();
    }
    return 0;
}