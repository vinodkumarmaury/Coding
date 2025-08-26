#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;

vector<int> vis;
vector<int> comp_num;
vector<int> comp_size;
void dfs(int node,int comp_no){
    vis[node]=1;
    comp_num[node] = comp_no;
    comp_size[comp_no]++;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v, comp_no);
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1);
    comp_num.resize(n+1);
    comp_size.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int comp_no = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            comp_no++;
            dfs(i,comp_no);
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(comp_num[a]==comp_num[b]){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<comp_size[comp_num[i]]<<endl;
    // }

    // for(auto v:comp_num)cout<<v<<" ";cout<<endl;
    // for(auto v:comp_size)cout<<v<<" ";cout<<endl;
    // dfs(1);
    // for(auto v:vis)cout<<v<<" ";cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}