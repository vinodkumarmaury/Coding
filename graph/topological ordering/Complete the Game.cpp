// Description
// A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?

// Input Format
// The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1, 2, …, n.
// After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.

// Output Format
// Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 109+7.

// Constraints
// 1 ≤ n ≤ 105
// 1 ≤ m ≤ 2 x 105
// 1 ≤ a, b ≤ n

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using state = pair<int,int>;
#define F first
#define S second
using ll = long long;
#define endl '\n'


vector<int> indeg;
vector<vector<int>>adj;
int n,m;

void kahn(){
    queue<int> q;
    for(int i = 0;i<n;i++){
        if(indeg[i]==0)q.push(i);
    }
    
    vector<ll> dp(n+1,0);
    dp[1] = 1;
 
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &v:adj[node]){
            dp[v] = (dp[v]+dp[node])%mod;
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }
        }
    }
    cout<<dp[n]<<endl;
}

void solve(){
    cin>>n>>m;
    adj.assign(n+1,{});
    indeg.assign(n+1,0);
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        indeg[b]++;
        adj[a].push_back(b);
    }
    
    kahn();

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}