#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
      int a,b;
      cin>>a>>b;
      v.push_back({b,a});
    }
    
    sort(v.begin(),v.end());
    long long start = 0;
    for(auto &num:v){
      if(num.first<start+num.second){
        cout<<"No"<<endl;
        return 0;
      }
      else{
        start+=num.second;
      }
    }
    cout<<"Yes"<<endl;
    
    return 0;
}