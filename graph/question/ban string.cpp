#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'
const int inf = 1e9;

vector<int> ban;
vector<vector<int>> adj;
vector<int> dist;
int stringToNum(string s){
    int ans = 0;
    for(int i = 0;i<20;i++){
        if(s[i]=='1'){
            ans |=(1<<i);
        }
    }
    return ans;
}

void add_edge(int a,int b){
    if(!ban[a]&&!ban[b]){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void BFS(int stVal){
dist.assign(1<<20,inf);
queue<int> q;
q.push(stVal);
dist[stVal] = 0;

while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(auto &node:adj[curr]){
        if(dist[node]>dist[curr]+1){
            dist[node] = dist[curr]+1;
            q.push(node);
        }
    }
}

}

void solve(){
adj.assign(1<<20,{});
string st;
cin>>st;
int stVal = stringToNum(st);
string end;
cin>>end;
int endval = stringToNum(end);
int  n;
cin>>n;
ban.assign(1<<20,0);
for(int i = 0;i<n;i++){
string x;
cin>>x;
int pos = stringToNum(x);
ban[pos] = 1;
}

for(int i = 0;i<(1<<20);i++){
    for(int j = 0;j<20;j++){
        add_edge(i,i^(1<<j));
    }
}

BFS(stVal);
cout<<dist[endval]<<endl;
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