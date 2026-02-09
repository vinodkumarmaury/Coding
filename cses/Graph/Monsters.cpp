#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define endl '\n'
using ll = long long;
using state = pair<int,int>;
int n,m;
vector<string> mat;
queue<state> monstor,person;
vector<vector<int>> dist_monstor,dist_person;
vector<state> exitPoint;
vector<vector<state>> par;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

bool isInside(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m&&mat[x][y]!='#')return 1;
    return 0;
}

vector<state> neighbour(state node){
    vector<state> ans;
    for(int k = 0;k<4;k++){  
    int x = node.F+dx[k];
    int y = node.S+dy[k];
    if(isInside(x,y)){
     ans.push_back({x,y});
    }
    }
    return ans;
}

void BFS_person(){
while(!person.empty()){
state node = person.front();
person.pop();
for(auto &v:neighbour(node)){
if(dist_person[v.F][v.S]>dist_person[node.F][node.S]+1){
    dist_person[v.F][v.S] = dist_person[node.F][node.S]+1;
    person.push(v);
    par[v.F][v.S] = node;
}
}
}
}

void BFS_monstor(){
    while(!monstor.empty()){
        state node = monstor.front();
        monstor.pop();
        for(auto &v:neighbour(node)){
        if(dist_monstor[v.F][v.S]>dist_monstor[node.F][node.S]+1){
            dist_monstor[v.F][v.S] = dist_monstor[node.F][node.S]+1;
            monstor.push(v);
        }
        }
    }
}

int main(){
    cin>>n>>m;
    mat.assign(n,"");
    state st;
    dist_monstor.assign(n,vector<int>(m,1e9));
    dist_person.assign(n,vector<int>(m,1e9));
    par.assign(n,vector<state>(m,{-1,-1}));
    for(int i = 0;i<n;i++){
     string s;
     cin>>s;
     mat[i] = s;
     for(int j = 0;j<m;j++){
        if(s[j]=='A'){
            if(i==0||i==n-1||j==0||j==m-1){
                cout<<"YES"<<endl;
                cout<<0<<endl;
                return 0;
            }
            st = {i,j};
            person.push({i,j});
            dist_person[i][j] = 0;
            par[i][j] = {-1,-1};
        }
        else if(s[j]=='M'){
            monstor.push({i,j});
            dist_monstor[i][j] = 0;
        }
        else if((i==0 || i==n-1 || j==0 || j==m-1) && s[j]=='.'){
        exitPoint.push_back({i,j});
        }
     }
    }
    
    BFS_person();
    BFS_monstor();
    bool isPossible = false;
    state en;
    for(auto &ex:exitPoint){
        int x = ex.F;
        int y = ex.S;
        if(dist_monstor[x][y]>dist_person[x][y]){
         isPossible = true;
         en = {x,y};
         break;
        }
    }
    if(!isPossible){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    vector<state> path;
    state curr = en;
    while(curr!=make_pair(-1,-1)){
        path.push_back(curr);
        curr = par[curr.F][curr.S];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()-1<<endl;
    int originX = st.F;
    int originY = st.S;
    string ans = "";
    for(int i = 1;i<(int)path.size();i++){
    int x = path[i].F;
    int y = path[i].S;
    if(x==originX){
        if(y>originY){
            ans+="R";
        }
        else{
            ans+="L";
        }
    }
    else{
        if(x>originX){
            ans+="D";
        }
        else{
            ans+="U";
        }
    }
    originX = x;
    originY = y;
    }
    cout<<ans<<endl;
    return 0;
}


