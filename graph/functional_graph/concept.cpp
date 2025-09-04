
// https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/CHEFRRUN

// functional graph -> start deleting those node whose indeg is 0



#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
#define endl '\n'

void solve(){
int n;
cin>>n;
vector<int> adj(n);
vector<int> indeg(n,0);
int arr[n];
for(int i = 0;i<n;i++){
    cin>>arr[i];
    adj[i] = (arr[i]+1+i)%n;
    indeg[adj[i]]++;
}

queue<int> q;

int count = 0;
for(int i = 0;i<n;i++){
    if(indeg[i]==0){
      q.push(i);
    }
}
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        indeg[adj[curr]]--;
        count++;
        if(indeg[adj[curr]]==0){
            q.push(adj[curr]);
        }
    }
    cout<<n-count<<endl;
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