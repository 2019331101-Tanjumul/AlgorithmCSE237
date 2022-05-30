/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-30 16:43:58
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

const int sz=5e5;

ll tot;

vector<int>node[sz];
ll weight[sz];
ll vis[sz];
ll a[sz];
ll n;
ll dis[sz], in[sz];
ll out[sz];
ll down[sz];

ll dfs_weight(int p, int parent)
{
         ll cur=0;
         vis[p]=1;

         for(auto child : node[p])
         {
              if(child==parent)
               continue;

              if(!vis[child])
              {
                   cur+=dfs_weight(child, p);

              }
              else
               cur+=weight[child];
         }

         return weight[p]=a[p]+cur;
}

ll dfs_in(int p,  int parent, int x)
{
 
         vis[p]=1;
         dis[p]=x;
 
         ll cur=a[p];
 
         ll mx=0;
 
         for(auto i:node[p])
         {
              if(i==parent)
               continue;
 
              if(!vis[i])
              {
                 mx+=dfs_in(i,p,dis[p]+1);
              }
              else
               mx+=in[i];
         }
 
         return in[p]=cur*dis[p]+mx;

}

void dfs(int p, int parent)
{
          
          vis[p]=1;
          ll cur=0;
          ll tempW=0;
          ll tempIN=0;
          for(auto child :node[p])
          {
                 if(child==parent)
                  continue;
                 tempIN+=in[child];
                 cur+=down[child];
                 tempW+=weight[child];
          }


          for(auto child : node[p])
          {
              if(vis[child]==0)
              {
                        
                        ll pans= cur -  down[child];
                        ll lans= tempW - weight[child];
                        
                        out[child]=out[p] + lans + lans + pans + tot - tempW;

                        dfs(child , p);

              }
          }
}

void Solve()
{  
         
          
          cin>>n;

          for(int i=1 ; i<=n ; i++)
            cin>>a[i],tot+=a[i];

          for(int i=1 ; i<n ; i++)
          {
               int x,y;
               cin>>x>>y;
               node[x].push_back(y);
               node[y].push_back(x);
          }

          dfs_weight(1, 0);
          
          for(int i=1 ; i<=n ; i++)
            vis[i]=0;


          dfs_in(1, 0, 0);
          

          for(int i=1 ; i<=n ; i++)
          {
              down[i] = in[i] - dis[i]*weight[i];
          }
          
          for(int i=1 ; i<=n ; i++)
            vis[i]=0;

          dfs(1,-1);
          ll ans=0;
          for(int i=1 ; i<=n ; i++)
            ans=max(ans, down[i]+out[i]);

          cout<<ans<<endl;


        
        
         
    
}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
           
          int tt=1;
         // cin>>tt;
          while(tt--)
          {
           
             Solve();
          }


          return 0;
        
}

//https://codeforces.com/contest/1092/problem/F