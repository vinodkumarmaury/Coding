#include<bits/stdc++.h>
using namespace std;

void helper(int n,int from,int to, int support,int k){
     if(k<=(1<<(n-1))-1){
          helper(n-1,from,support,to,k);
     }
     else if(k==(1<<(n-1))){
          cout<<"Move "<<from<<" src "<<to<<endl;
     }
     else{
          helper(n-1,support,to,from,k-(1<<(n-1)));
     }
}

int main(){
     int n,k;
     cin>>n>>k;
     helper(n,1,3,2,k);
     return 0;
}