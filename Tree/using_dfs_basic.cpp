#include<bits/stdc++.h>
using namespace std;
using ll  = long long;

// 7
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7


vector<int> g[1000100];
int par[1000100];
int dep[1000100];
int substree[1000100];
bool isLeaf[1000100];
int numChild[1000100];

void dfs(int node, int parent,int depth){
    par[node] = parent;
    dep[node] = depth;
    numChild[node] = 0;
    substree[node] = 1;

    for(auto &v:g[node]){
        if(v!=parent){
            numChild[node]++;
            dfs(v,node,depth+1);
            substree[node]+=substree[v];
        }
    }
    if(numChild[node]==0){
        isLeaf[node] = 1;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    cout << "Node | Parent | Depth | SubtreeSize | NumChildren | IsLeaf\n";
    for(int i=1;i<=n;i++){
        cout << i << "     | "
             << par[i] << "      | "
             << dep[i] << "     | "
             << substree[i] << "           | "
             << numChild[i] << "           | "
             << (isLeaf[i] ? "Yes" : "No") << "\n";
    }
}