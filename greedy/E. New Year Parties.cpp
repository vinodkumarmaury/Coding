#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int maxi = 1,mini = 1;
    
    int last = v[0]-1;
    
    for(int i = 1;i<n;i++){
      if(v[i]-1>last){
        last = v[i]-1;
        maxi++;
      }
      else if(v[i]>last){
        last = v[i];
        maxi++;
      }
      else if(v[i]+1>last){
        last = v[i]+1;
        maxi++;
      }
    }
    
    last = v[0]+1;
    
    for(int i = 1;i<n;i++){
      bool found = false;
      for(int j = -1;j<=1;j++){
        if(v[i]+j==last){
          found = true;
          break;
        }
      }
      if(found)continue;
      last = v[i]+1;
      mini++;
    }
    cout<<mini<<" "<<maxi<<endl;
    return 0;
}



