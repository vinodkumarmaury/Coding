#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'


int n,k,t;
vector<int> timesGiven;
vector<int> scoreGiven;
int times = 0;
int subject = 0; 
int rec(int level){
    
    // prune 
    if(subject>k||times>t)return -1e9;

    // base case
    if(level==n){
        return 0;
    }
  
    // choice

// Not take;
int score = rec(level+1);
// taken
if(timesGiven[level]+times<=t&&subject<k){ // check
times = times+timesGiven[level];
subject++;
score = max(score,rec(level+1)+scoreGiven[level]);  // move
times = times-timesGiven[level];
subject--;
}
return score;
}

void solve(){
cin>>n>>k>>t;
timesGiven.clear();
scoreGiven.clear();
subject = 0;
times = 0;
for(int i = 0;i<n;i++){
    int x,y;
    cin>>x>>y;
    timesGiven.push_back(x);
    scoreGiven.push_back(y);
}

cout<<rec(0)<<endl;

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