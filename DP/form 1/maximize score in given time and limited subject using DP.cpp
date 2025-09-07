#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'


int n,k,t;
vector<int> timesGiven;
vector<int> scoreGiven;

int dp[500][50][1000];

int rec(int level,int subject,int times){
    
    // prune 
    if(subject>k||times>t)return -1e9;

    // base case
    if(level==n){
        return 0;
    }
  
  if(dp[level][subject][times]!=-1){
    return dp[level][subject][times];
  }

    // choice

// Not take;
int score = rec(level+1,subject,times);
// taken
if(timesGiven[level]+times<=t&&subject<k){ // check
score = max(score, rec(level+1, subject+1, times+timesGiven[level]) + scoreGiven[level]);
  // move
}
return dp[level][subject][times] =  score;
}

void solve(){
cin>>n>>k>>t;
memset(dp,-1, sizeof(dp));
timesGiven.clear();
scoreGiven.clear();
for(int i = 0;i<n;i++){
    int x,y;
    cin>>x>>y;
    timesGiven.push_back(x);
    scoreGiven.push_back(y);
}

cout<<rec(0,0,0)<<endl;

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