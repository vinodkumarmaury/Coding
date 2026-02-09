#include<bits/stdc++.h>
using namespace std;
using ll  = long long;

const int x = 2*1e5+5;

vector<int> g[x];
int par[x];
int dep[x];
int D,cnt;

void dfs(int node, int parent,int depth){
    par[node] = parent;
    dep[node] = depth;
    for(auto &v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}

// count nodes at given depth inside a subtree
int count_depth(int node,int parent,int depth,int target){
    if(depth==target) return 1;
    if(depth>target) return 0;
    int res=0;
    for(auto v:g[node]){
        if(v!=parent){
            res += count_depth(v,node,depth+1,target);
        }
    }
    return res;
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
    if(n==1){
        cout<<1<<endl;
        return 0;
    }

    // find one endpoint of diameter
    dfs(1,0,0);
    int maxchld = 1;
    for(int i = 2;i<=n;i++){
        if(dep[i]>dep[maxchld]){
            maxchld = i;
        }
    }

    // find other endpoint
    dfs(maxchld,0,0);
    maxchld = 1;
    for(int i = 2;i<=n;i++){
        if(dep[i]>dep[maxchld]){
            maxchld = i;
        }
    }

    // recover path
    vector<int> path;
    for(int node=maxchld; node!=0; node=par[node]) path.push_back(node);

    D = path.size()-1; 

    ll ans=0;

    if(D%2==0){
        // single center
        int center = path[D/2];
        int target = D/2;
        vector<int> counts;
        for(auto v:g[center]){
            counts.push_back(count_depth(v,center,1,target));
        }
        ll sum=0;
        for(auto c:counts){
            ans += 1LL*c*sum;
            sum += c;
        }
    }
    else{
        // two centers
        int c1 = path[D/2];
        int c2 = path[D/2+1];
        int target = D/2;
        int k1 = count_depth(c1,c2,0,target);
        int k2 = count_depth(c2,c1,0,target);
        ans = 1LL*k1*k2;
    }

    cout<<ans<<endl;
    return 0;
}
