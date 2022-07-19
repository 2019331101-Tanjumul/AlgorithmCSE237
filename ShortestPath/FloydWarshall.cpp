/*
* @Author: Zakaria 
* @Date:   2022-03-31 00:15:02
* @Last Modified time: 2022-03-31 00:15:02
*/

#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;                                                           
const ll inf=LLONG_MAX;
ll n,m,p,q,k,w;
ll node[504][504];
ll dis[503][504];
ll vis[504][504];
void warshall(ll n)
{
 
    for(int k=1;k<=n;k++)
    {
          for(int i=1;i<=n;i++)
          {
             for(int j=1;j<=n;j++)
             {
                
                 dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
             }
          }
    }
}
 
 
 
int main()
{
      
       ios::sync_with_stdio(false);
       cin.tie(0);
        
        cin>>n>>m>>k;
       
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=n;j++)
         {
              dis[i][j]=inf;
         }
         dis[i][i]=0;

      }
 
        while(m--)
        {
             cin>>p>>q>>w;
             
             dis[p][q]=min(dis[p][q],w);
             dis[q][p]=min(dis[q][p],w); 
 
        }
 
      
     
      warshall(n);
 
     while(k--)
     {
         cin>>p>>q;
         if(p==q)
            cout<<0<<endl;
         else if(dis[p][q]>=inf||dis[p][q]<0)
            cout<<-1<<endl;
        else
          cout<<dis[p][q]<<endl;
     }

     
 
      
     return 0;
 }
    
