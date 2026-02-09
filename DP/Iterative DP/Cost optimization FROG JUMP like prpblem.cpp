// here we can make 1 to k move and cost is summatino of all path used, we have to minimize the cost
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

const int inf = 1e9;

struct monotone_deque{

deque<int> dq;

void insert(int x){
    while(!dq.empty()&&(dq.back()>x)){
        dq.pop_back();
    }
    dq.push_back(x);
}

void erase(int x){
    if(dq.front()==x)dq.pop_front();
}

int getMin(){
    return dq.front();
}
};


void solve(){
int n,k;
cin>>n>>k;
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
}
vector<int> dp(n+1,inf);

monotone_deque mt;
dp[0] = arr[0];
for(int i = 1;i<n;i++){
    mt.insert(dp[i-1]);
    if(i-k-1>=0)mt.erase(dp[i-k-1]);
    dp[i] = mt.getMin()+arr[i];
}

cout<<dp[n-1]<<endl;
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