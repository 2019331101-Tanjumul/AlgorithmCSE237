/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-27 20:50:13
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         500002
typedef long long ll;
using namespace std;

const int sz=5e5+5;
int a[sz];
int vis[sz], in[sz], out[sz];
vector<int>node[sz];

int dfs_in(int parent, int p)
{

         vis[p]=1;
         int cur=a[p];
         int mx=0;
      
         for(auto i:node[p])
         {
            
              if(i==parent)
               continue;

             if(!vis[i])
               mx+=max(0, dfs_in(p, i));
             else
               mx+=max(0, in[i]);
         }
         
         in[p]+=(mx+cur);

         return in[p];
}

void dfs_out( int p)
{
         
        int mx=0;
        vis[p]=1;

        for(auto i:node[p])
        {
              if(vis[i])
               continue;
              mx+=max(0, in[i]);
        }

        for(auto i:node[p])
        {
            if(!vis[i])
            {
                  int pans=mx-max(0,in[i]);
                  out[i]=max(0,a[p]+pans+max(0, out[p]));
                  dfs_out(i);
            }
        }


}
void Solve()
{  
      
          int n;
          cin>>n;
          
          for(int i=1 ; i<=n ; i++)
            cin>>a[i];

          for(int i=1 ; i<=n ; i++)
          {
             if(!a[i])
               a[i]=-1;
          }

          for(int i=1 ; i<n ; i++)
          {
              int x, y;
              cin>>x>>y;
              node[x].push_back(y);
              node[y].push_back(x);
          }


          dfs_in(-1, 1);

          for(int i=1 ; i<=n ; i++)
            vis[i]=0;
          
          dfs_out(1);



          for(int i=1 ; i<=n ; i++)
            cout<<in[i]+out[i]<<" ";

          cout<<endl;
         

            
         
}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
          


          int tt=1;
       //   cin>>tt;
          while(tt--)
          {
           
             Solve();
          }


          return 0;
        
}

//https://codeforces.com/contest/1324/problem/F/