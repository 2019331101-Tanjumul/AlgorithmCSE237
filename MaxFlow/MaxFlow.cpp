/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-23 10:38:39
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
#define  MAX         200002
typedef long long ll;
using namespace std;

const int N=1010;

int capacity[N][N];
int vis[N], parent[N];
int n,m;
vector<int>path;
int src, sink;

void dfs(int p)
{
       vis[p]=1;
      
       for(int i=0 ; i<n ; i++)
       {
           if(capacity[p][i] && !vis[i])
           {
               parent[i]=p;
               dfs(i);
           }
       }
}

void FindPath(int src, int sink)
{
         
         memset(vis, 0 , sizeof(vis));
         memset(parent, -1, sizeof(parent));

         dfs(src);
         path.clear();

         if(!vis[sink])
            return;

         int cur_node=sink;

         while(cur_node!=-1)
         {
             path.push_back(cur_node);
             cur_node=parent[cur_node];
         }

         return;


}


int MaxFlow(int src ,  int sink)
{
             
         int flow=0;

         while(1)
         {

              path.clear();

              FindPath(src, sink);

              if(path.size()==0)
              {
                  break;
              }
              reverse(path.begin(), path.end());
             
              int mnFlow=INT_MAX;

              for(int i=0 ; i<path.size()-1 ; i++)
              {
                     int u=path[i];
                     int v=path[i+1];
                     mnFlow=min(mnFlow, capacity[u][v]);
              }

              flow+=mnFlow;
            
              for(int i=0 ; i<path.size()-1 ; i++)
              {
                   int u=path[i];
                   int v=path[i+1];
                   capacity[u][v]-=mnFlow;
                   capacity[v][u]+=mnFlow;
              }
         }
         return flow;

}


int main()
{
         
              ios::sync_with_stdio(false);
              cin.tie(0);
         
              
              cin>>n>>m;
              
              for(int i=0 ; i<m ; i++)
              {
                   int a,b,w;
                   cin>>a>>b>>w;
                   capacity[a][b]=w;
              }

            
              cin>>src>>sink;

              int ans;
              ans=MaxFlow( src, sink);
              cout<<ans<<endl;



          return 0;
        
}