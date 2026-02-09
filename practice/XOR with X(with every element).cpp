#include <bits/stdc++.h>
using namespace std;

// 3
// 1 1 3
// 1 7 9
// Output:
// 22

vector<int> type;
const int N = 32;

unordered_map<int,int> mp;
vector<int> bits(N,0);
int n = 0;
void add(int x){
  for(int i = 0;i<N;i++){
    if((x>>i)&1){
      bits[i]++;
    }
  }
  mp[x]++;
  n++;
}

void erase(int x){
  int occ = mp[x];
  for(int i = 0;i<N;i++){
    if((x>>i)&1){
      bits[i]-=occ;
    }
  }
  mp[x] = 0;
  n-=occ;
}

long long query(int x){
  long long ans = 0;
  for(int i = 0;i<32;i++){
    if((x>>i)&1){
      ans+=(n-bits[i])*(1<<i);
    }
    else{
      ans+=(bits[i])*(1<<i);
    }
  }
  return ans;
}

int main() 
{
    int q;
    cin>>q;
    type.assign(q+1,-1);
    for(int i = 0;i<q;i++){
      cin>>type[i];
    }
    for(int i = 0;i<q;i++){
      int x;
      cin>>x;
      if(type[i]==1){
        add(x);
      }
      else if(type[i]==2){
        erase(x);
      }
      else{
        cout<<query(x);
      }
    }
    return 0;
}