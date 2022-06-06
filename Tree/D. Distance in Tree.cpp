/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-06-07 04:09:45
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
#define  MAX         1000002
typedef long long ll;
using namespace std;

const int sz=50002;

int in[sz][505], out[sz][505];

vector<int>node[sz];
int vis[sz];
int dis[sz];

int n,len, prev;

void dfs_in(int p, int parent, int d)
{
          
          dis[p]=d;
          vis[p]=1;

          for(auto child : node[p])
          {
              if(!vis[child])
                dfs_in(child, p, dis[p]+1);
          }

          in[p][0]=1;

          for(auto child : node[p])
          {
              if(child==parent)
                continue;
              for(int j=1; j<=len ; j++)
              in[p][j]+=in[child][j-1];
          }

        

}

void dfs_out(int p, int parent, int k)
{
              
             
           int mx=0;

           for(auto child : node[p])
           {
               if(child!=parent)
               {
                   mx+=in[child][k-2];
               }
           }


           for(auto child : node[p])
           {
                if(child==parent)
                  continue;

                ll pans=mx-in[child][k-2];

                out[child][k]=out[p][k-1]+pans;
                dfs_out(child, p, k);
           }
             

}

void Solve()
{  
            
             cin>>n>>len;

             for(int i=1 ; i<n ; i++)
             {
                 int x,y;
                 cin>>x>>y;
                 node[x].push_back(y);
                 node[y].push_back(x);
             }
             
             dfs_in(1, 0, 0);
           
             for(int i=1 ;i<=n ; i++)
              vis[i]=0;

            for(int k=1 ; k<=len ;k++)
            {
                
                 if(k==1)
                 {
                      for(int i=2 ; i<=n ; i++)
                        out[i][1]=1;
                      continue;
                 }
                  
                  dfs_out(1, 0 , k);
            }
            

           ll ans=0;

           for(int i=1; i<=n ; i++)
            ans+=in[i][len]+out[i][len];

           cout<<ans/2<<endl;
         
}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
           
          int tt=1;
      //    cin>>tt;
          while(tt--)
          {
           
             Solve();
          }


          return 0;
        
}