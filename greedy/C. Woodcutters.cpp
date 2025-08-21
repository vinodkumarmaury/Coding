#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++){
      cin>>v[i].first>>v[i].second;
    }
    
    if(n==1){
      cout<<1<<endl;
      return 0;
    }
    
    int ans = 0;
    int last = v[0].first;
    for(int i = 1;i<n-1;i++){
      int lenLeft = v[i].first - v[i].second;
      if(lenLeft>last){
        ans++;
        last = v[i].first;
      }
      else if(v[i].first+v[i].second<v[i+1].first){
        ans++;
        last = v[i].first+v[i].second;
      }
      else{
        last = v[i].first;
      }
    }
    cout<<ans+2<<endl;
    return 0;
}