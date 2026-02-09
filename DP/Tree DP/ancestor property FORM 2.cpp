#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// assign value between 1 to m so for every path gcd from root to leaf is 1
const int N = 1e5+5;
vector<int> g[N];
int indp[N];
int outdp[N];
int ans[N];
int dp[N][21]; // m can be upto 20
int n,m;


int gcd(int a,int b){
    if(a==0||b==0)return a^b;
    else return gcd(b,a%b);
}

int rec(int node,int gc,int pp){

    // if(g[node].size()==0||g[node].size()==1&&pp!=0)return 1; // no need to write it because we are already handling it by counting leaf node

    if(dp[node][gc]!=-1)return dp[node][gc];

    int ans = 0;
    for(int col = 1;col<=m;col++){
        int temp = 1;
        int cntch = 0;
        for(auto&v:g[node]){
            if(v!=pp){
            cntch++;
            temp *=rec(v,gcd(gc,col),node);
            }
        }
        if(cntch==0){
            if(gcd(gc,col)==1){
                ans++;
            }
        }
        else{
            ans+=temp;
        }
    }
    return dp[node][gc] = ans;
}

void solve(){
cin>>n>>m;
memset(dp,-1,sizeof(dp));
for(int i = 0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
cout<<rec(1,0,0)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}