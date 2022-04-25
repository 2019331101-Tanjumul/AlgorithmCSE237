/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-04-25 13:52:25
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

vector<int>node[MAX];
int vis[MAX];
int dis[MAX],repeat[MAX];
vector<int>visited;
int n,m;
string s;
char c;

bool isCycle(int p)
{
     
     vis[p]=1;

     for(int child:node[p])
     {
          if(vis[child]==0)
          {
             if(isCycle(child)==1)
               return 1;
          }
          else
          {
             if(vis[child]==1)
               return 1;
          }
     }
     vis[p]=2;

     return 0;
}

void Unvisit()
{
      for(int i=0 ; i<=n ; i++)
         vis[i]=0,dis[i]=0;

}

int dfs(int p)
{
     vis[p]=1;
     int cur=(s[p]==c);
     dis[p]+=cur;
     int mx=0;
     for(auto i:node[p])
     {
         if(!vis[i])
         {
             mx=max(mx,dfs(i));
         }
         mx=max(mx,dis[i]);
     }

     dis[p]+=mx;

     return dis[p];


}


void Solve()
{
      
           
           cin>>n>>m;
           cin>>s;
           s='*'+s;


           for(int i=1 ; i<=m ; i++)
           {
               int x,y;
               cin>>x>>y;
               node[x].push_back(y);
               
           }

           for(int i=1 ; i<=n ; i++)
           {
               if(!vis[i])
               {
                    if(isCycle(i))
                    {
                       cout<<-1<<endl;
                       return ;
                    }
               }
           }
           
           for(int i=1 ; i<=n ; i++)
            vis[i]=0,dis[i]=0;
           int ans=0;

          
                        
            for(char k='a' ; k<='z' ; k++)
            {
                for(int i=1 ; i<=n ; i++)
                {
                    if(vis[i])
                        continue;
                  
                    c=k;
                   int temp=dfs(i);
                   ans=max(ans,temp);
                
                   
                }

                Unvisit();
                
            }

                 

           

           cout<<ans<<endl;





}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
           
          int tt=1;
          //cin>>tt;
          while(tt--)
          {
             Solve();
          }


          return 0;
        
}