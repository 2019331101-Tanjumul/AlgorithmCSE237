/*
* @Author: Zakaria 
* @Date:   2022-03-30 17:50:53
* @Last Modified time: 2022-03-31 03:04:07
*/


#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         20000002
typedef long long ll;
using namespace std;



struct edge
{
    int u;
    int v;
    int w;
    
};

edge a[100005];
int parent[100005];

bool comp (edge a , edge b)
{
  return a.w < b.w; ///sorting Ascencding order 
}

int find_parent(int u) ///DSU find 
{
    
    if(parent[u]==-1)
      return u;
    else
      return parent[u]=find_parent(parent[u]);
}

void merge(int u, int v) /// DSU union 
{
    parent[u]=v;
}

int main()
{
    
      ios::sync_with_stdio(false);
      cin.tie(0); 
   
   

      int n,m,w;
      

      cin>>n>>m;
      for(int i=1;i<=n;i++)
        parent[i]=-1;
      
      for(int i=0;i<m;i++)
       {
         cin>>a[i].u>> a[i].v >> a[i].w;
       }

      sort(a,a+m,comp);
     
      ll ans=0;
      
      for(int i=0;i<m;i++)
      {
         int x=find_parent(a[i].u);
         int y=find_parent(a[i].v);

         if(x!=y)
         {
            merge(x,y);
            ans+=a[i].w;
         }

       }


       cout<<ans<<endl;

    

        
    
 
return 0;           
    
              
}
