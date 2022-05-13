/*
* @Author: Zakaria 
* @Date:   2022-03-07 23:36:26
* @Last Modified time: 2022-05-13 11:25:40
*/

/*1. Make sure the graph has either 0 or 2 odd vertices.
2. If there are 0 odd vertices, start anywhere. If there are 2 odd vertices, start at one of them.
3. Follow edges one at a time. If you have a choice between a bridge and a non-bridge, always choose the non-bridge.
4. Stop when you run out of edges.*/

#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;  

int adj[1000][100];
int n,m;
int vis[1000];

int DfsCount(int x)
{
     vis[x]=1;
     int cnt1=1;

     for(int i=1 ;i<=n ; i++)
     {
         if(adj[x][i] && !vis[i])
            cnt1+=DfsCount(i);
     }
     return cnt1;
}

bool isValidNextEdge(int par , int child)
{
         memset(vis,0,sizeof(vis));
         
         int cnt1=DfsCount(par);

         memset(vis,0,sizeof(vis));

         adj[par][child]=0;
         adj[child][par]=0;

         int cnt2=DfsCount(par);
         
         adj[par][child]=1;
         adj[child][par]=1;

         if(cnt1==cnt2)
            return 1;
         else
            return 0;
         
}

void EularTraverse(int x)
{
     
      for(int i=1 ; i<=n ; i++)
      {
           
            if(adj[x][i] && isValidNextEdge(x, i))
            {
                 int next=i;
                 cout<<x<<"----"<<next<<endl;
                 adj[x][next]=0;
                 adj[next][x]=0;
                 EularTraverse(next);
            }
      }

      for(int i=1 ; i<=n ; i++)
      {
          if(adj[x][i])
          {
             cout<<x<<"----"<<i<<endl;
             adj[x][i]=0;
             adj[i][x]=0;
             EularTraverse(i);
          }
      }
}


int main()
{
      
        ios::sync_with_stdio(false);
        cin.tie(0);
        

        
        cin>>n>>m;
        for(int i=1 ; i<=m ; i++)
        {
              int x,y;
              cin>>x>>y;
              adj[x][y]=1;
              adj[y][x]=1;
        }

        int node=1;
        for(int i=1 ; i<=n ; i++)
        {
             int cnt=0;

              for(int j=1 ; j<=n ; j++)
              {
                  if(adj[i][j])
                    cnt++;
              }

              if(cnt%2)
                node=i;
        } 

        cout<<"Eular Circuit is :\n";

        EularTraverse(node);




        return 0;
}