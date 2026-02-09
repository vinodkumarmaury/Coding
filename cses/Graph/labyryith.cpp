#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using state = pair<int,int>;
vector<string> mat;
vector<vector<int>> dist,vis;
vector<vector<state>> par;
int n,m;
state st,en;
#define endl '\n'

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

void BFS(state stt){
queue<state> q;
q.push(stt);
dist[stt.first][stt.second] = 0;
par[stt.first][stt.second] = {-1,-1};
while(!q.empty()){
    state temp = q.front();
    vis[temp.first][temp.second] = 1;
    q.pop();
    for(auto &v:neighbour(temp)){
       int x = v.first;
       int y = v.second;
       if(dist[x][y]>dist[temp.first][temp.second]+1){
        dist[x][y] = dist[temp.first][temp.second]+1;
        q.push({x,y});
        par[x][y] = temp;
       }
    }
}
}

int main(){
    cin>>n>>m;
    mat.resize(n);
    for(int i = 0;i<n;i++){
        cin>>mat[i];
    }
    
    dist.assign(n+1,vector<int>(m+1,1e9));
    vis.assign(n+1,vector<int>(m+1,0));
    par.assign(n+1,vector<state>(m+1,{-1,-1}));

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char c = mat[i][j];
            if(c=='A'){
               st = {i,j};
            }
            else if(c=='B'){
                en = {i,j};
            }
        }
    }

    BFS(st);
    if(!vis[en.first][en.second]){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    vector<state> path;
    
    state temp = en;

    while(temp!=make_pair(-1,-1)){
        path.push_back(temp);
        temp = par[temp.first][temp.second];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()-1<<endl;
    
    string ans = "";
    int originX = st.first;
    int originY = st.second;
    for(int i = 1;i<path.size();i++){
     int x = path[i].first;
     int y = path[i].second;
     if(x==originX){
        if(y>originY){
            ans+="R";
        }
        else{
            ans+="L";
        }
        originY = y;
     }
     else{
        if(x>originX){
            ans+="D";
        }
        else{
            ans+="U";
        }
        originX = x;
     }
    }
    cout<<ans<<endl;
  
  return 0;
}


