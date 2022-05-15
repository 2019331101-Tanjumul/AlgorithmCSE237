/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-16 01:17:27
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

          int n,m;
          cin>>n>>m;

          for(int i=1 ; i<=m ; i++)
          {
              int x,y;
              cin>>x>>y;
              node[x].push_back(y);
              node[y].push_back(x);
          }

          dfs_in(1);

          memset(vis, 0 ,sizeof(vis));

          dfs_out(1);


         

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

//problem : https://cses.fi/problemset/task/1132/

//editorial : https://blogarithms.github.io/articles/2019-10/inout-dp-tree#:~:text=This%20is%20where%20in%2Dout%20DP%20comes%20in.&text=in%20is%20an%20array%20that,for%20a%20given%20current%20node.