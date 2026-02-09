#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using state = pair<int,int>;
vector<string> mat;
vector<vector<int>> vis;
int n,m;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

bool isInside(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m)return true;
    return false;
}

vector<state> neighbour(state temp){
    vector<state> ans;
    int i = temp.first;
    int j = temp.second;
    for(int k = 0;k<4;k++){
        int x = i+dx[k];
        int y = j+dy[k];
        if(isInside(x,y)&&mat[x][y]!='#'){
          ans.push_back({x,y});
        }
    }
    return ans;
}

void BFS(int i,int j){
queue<state> q;
q.push({i,j});
while(!q.empty()){
    auto temp = q.front();
    q.pop();
    if(vis[temp.first][temp.second])continue;
    vis[temp.first][temp.second] = 1;
    for(auto &v:neighbour(temp)){
       int x = v.first;
       int y = v.second;
       q.push({x,y});
    }
}
}

int main(){
    
    cin>>n>>m;
    mat.resize(n);
    for(int i = 0;i<n;i++){
        cin>>mat[i];
    }
    
    vis.assign(n+1,vector<int>(m+1,0));
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char c = mat[i][j];
            if(c=='.'&&!vis[i][j]){
                BFS(i,j);
                count++;
            }
        }
    }
  cout<<count<<endl;
  return 0;
}