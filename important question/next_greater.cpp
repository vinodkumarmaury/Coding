#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
      cin>>arr[i];
    }
    
   vector<int> next(n,-1);
    stack<int> st;
    st.push(n-1);
    for(int i = n-2;i>=0;i--){
      while(!st.empty()&&arr[st.top()]<=arr[i])st.pop();
      if(!st.empty()){
      next[i] = arr[st.top()];
      }
      st.push(i);
    }
    for(int i = 0;i<n;i++){
      cout<<next[i]<<" ";
    }
    return 0;
}