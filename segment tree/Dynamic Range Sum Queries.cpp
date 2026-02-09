#include <bits/stdc++.h>
using namespace std;

int n,q;
const int N = 2e5+5;
int arr[N];


struct Node{
  int sum;
  Node(int m = 0){
    sum = m;
  }
};

Node t[4*N];
Node combine(Node a,Node b){
  Node c;
  c.sum = a.sum+b.sum;
  return c;
}

void build(int index,int l,int r){
  if(l==r){
    t[index] = Node(arr[l]);
    return;
  }
  int mid = (l+r)/2;
  build(index*2,l,mid);
  build(index*2+1,mid+1,r);
  t[index] = combine(t[index*2],t[index*2+1]);
}

void update(int index,int l,int r,int id,int val){
  if(id>r||id<l){
    return;
  }
  if(l==r){
    t[index] = Node(val);
    arr[l] = val;
    return;
  }
  int mid = (l+r)/2;
  update(index*2,l,mid,id,val);
  update(index*2+1,mid+1,r,id,val);
  t[index] = combine(t[index*2],t[index*2+1]);
}

Node query(int index,int l,int r,int lq,int rq){
  if(rq<l||lq>r){
    return Node();
  }
  if(lq>=l&&rq<=r){
    return t[index];
  }
  int mid = (l+r)/2;
  return combine(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
}

int main() 
{
    cin>>n>>q;
    for(int i = 0;i<n;i++){
      cin>>arr[i];
    }
    build(1,0,n-1);
    
    while(q--){
      int type;
      cin>>type;
      if(type==1){
        int k,u;
        cin>>k>>u;
        update(1,0,n-1,k-1,u);
      }
      else{
        int a,b;
        cin>>a>>b;
        Node ans = query(1,0,n-1,a-1,b-1);
        cout<<ans.sum<<endl;
      }
    }
    
    return 0;
}