#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> arr;

void print(int count){
  cout<<count<<"th correct queen position"<<endl;
  for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++){
        cout<<arr[i][j];
      }
      cout<<endl;
    }
}


bool check(int row,int col){
  for(int i = 0;i<row;i++){
    for(int j = 0;j<n;j++){
      if(arr[i][j]=='Q'){
      if(j==col||abs(j-col)==abs(i-row))return false;
      }
    }
  }
  return true;
}

void helper(int level,int &count){
  // level
  if(level==n){
    count++;
    print(count);
    return;
  }
  // choices;
  for(int i = 0;i<n;i++){
    // check
    if(check(level,i)){
      // Move
      arr[level][i] = 'Q';
      helper(level+1,count);
      arr[level][i] = '.';
    }
  }
}

int main() 
{
  cin>>n;
  arr.assign(n,vector<char>(n,'.'));
    for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++){
        cin>>arr[i][j];
      }
    }
    int count = 0;
    helper(0,count);
    
    return 0;
}