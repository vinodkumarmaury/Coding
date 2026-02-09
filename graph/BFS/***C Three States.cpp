#include<bits/stdc++.h>
using namespace std;
using state = pair<pair<int,int>,int>;
const int inf = 1e9;
#define F first
#define S second

int n,m;
vector<string> v;
vector<vector<vector<int>>> dist,vis;
deque<state> dq;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool isValidMove(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&v[x][y]!='#')return 1;
    return 0;
}

vector<state> neigbour(state curr){
    vector<state> ans;
    for(int k = 0;k<4;k++){
     int x = curr.F.F+dx[k];
     int y = curr.F.S+dy[k];
     if(isValidMove(x,y)){
      if(v[x][y]=='.'){
        ans.push_back({{x,y},1});
      }
      else{
        ans.push_back({{x,y},0});
      }
     }
    }
    return ans;
}

void BFS(){
while(!dq.empty()){
    state curr = dq.front();
    dq.pop_front();
    // vis[curr.F.F][curr.F.S][curr.S] = 1;
    for(auto node:neigbour(curr)){
        int x = node.F.F;
        int y = node.F.S;
        int z = node.S;
        // if(vis[x][y][z])continue;
        if(dist[x][y][curr.S]>dist[curr.F.F][curr.F.S][curr.S]+z){
            dist[x][y][curr.S] = dist[curr.F.F][curr.F.S][curr.S]+z;
            if(z==1){
            dq.push_back({{x,y},curr.S});
            }
            else{
             dq.push_front({{x,y},curr.S});
            }
        }
    }
}
}

void solve(){
    cin>>n>>m;
   dist.assign(n,vector<vector<int>>(m,vector<int>(4,inf)));
   vis.assign(n,vector<vector<int>>(m,vector<int>(4,0)));
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
        for(int j = 0;j<m;j++){
            if(s[j]=='1'||s[j]=='2'||s[j]=='3'){
                int val = s[j]-'0';
                dist[i][j][val] = 0;
                dq.push_back({{i,j},val});
            }
        }
    }

   BFS();
  
//   for(int k = 0;k<4;k++){
//     cout<<"for no of Bridges "<<k<<endl;
//   for(int i = 0;i<n;i++){
//     for(int j = 0;j<m;j++){
//             cout<<dist[i][j][k]<<" ";
//         }
//         cout<<endl;
//     }
//   }

   long long cost = inf;
   for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        if(v[i][j]!='#'){
        long long temp = 1LL*dist[i][j][1]+dist[i][j][2]+dist[i][j][3];
        if(v[i][j]=='.')temp-=2;
        cost = min(cost,temp);
        }
    }
   }
 if(cost==inf){
    cout<<-1<<endl;
 }
 else{
    cout<<cost<<endl;
 }
}


int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
solve();
return 0;
}



