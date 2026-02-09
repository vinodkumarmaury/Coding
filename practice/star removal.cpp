#include <bits/stdc++.h>
using namespace std;
using state = pair<int,int>;

// Mathworks OA

int main() 
{
    string s;
    cin>>s;
    priority_queue<state> pq;
    int  n = s.length();
    for(int i = 0;i<n;i++){
      if(s[i]=='*'){
        if(!pq.empty())pq.pop();
      }
      else{
        pq.push({-s[i],-i});
      }
    }
    
    vector<int> arr(n+1,0);
    
    while(!pq.empty()){
      auto it = pq.top();
      pq.pop();
      int index = it.second;
      arr[-index] = 1;
    }
    
    string ans = "";
    for(int i = 0;i<n;i++){
      if(arr[i]==1){
        ans+=s[i];
      }
    }
    cout<<ans<<endl;
    return 0;
}