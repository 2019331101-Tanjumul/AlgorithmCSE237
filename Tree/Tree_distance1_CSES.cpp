/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-16 01:15:48
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
int in[MAX];
int out[MAX];


void dfs_in(int parent)
{
     vis[parent]=1;
     in[parent]=0;

     for(auto child:node[parent])
     {
         if(!vis[child])
         {
              dfs_in(child);
              in[parent]=max(in[parent], 1+in[child]);
         }
     }
}

void dfs_out(int parent)
{
      vis[parent]=1;

      int mx1=-1;
      int mx2=-1;

      for(auto child:node[parent])
      {
          if(vis[child])
            continue;

          if(in[child]>=mx1)
          {
              mx2=mx1;
              mx1=in[child];      /*here find two max beacause is as for some
                                  particular child, the optimal answer 
                                  would’ve been present inside its own subtree*/
          }
          else if(in[child]>=mx2)
          {
              mx2=in[child];
          }
      }


      for(auto child : node[parent])
      {
           if(!vis[child])
           {
                int use=mx1;
                if(in[child]==mx1)
                    use=mx2;

                out[child]=max(2+use, 1+out[parent]);

                dfs_out(child);
           }
      }
}

void Solve()
{  

          int n;
          cin>>n;

          for(int i=1 ; i<n ; i++)
          {
              int x,y;
              cin>>x>>y;
              node[x].push_back(y);
              node[y].push_back(x);
          }

          dfs_in(1);

          for(int i=1 ; i<=n ; i++)
            vis[i]=0;

          dfs_out(1);

        

          for(int i=1 ; i<=n ; i++)
            cout<<max(in[i],out[i])<<" ";
          
          cout<<endl;
            
         

}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
           
          int tt=1;
        //  cin>>tt;
          while(tt--)
          {
             Solve();
          }


          return 0;
        
}