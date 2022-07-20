/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-07-17 11:54:03
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
#define  MAX         200000
typedef long long ll;
using namespace std;

vector<int>node[MAX];
int lca[MAX][31];
int level[MAX];
int n;
void dfs(int p, int par, int dis)
{
      lca[p][0]=par;
      
      for(auto i:node[p])
      {
            if(i!=par)
            {
                  level[i]=level[p]+1;
                  dfs(i, p, level[i]);
            }
      }
}

void init()
{
       memset(lca, -1, sizeof(lca));

        dfs(1, -1, 0);
        for(int j=1 ; j<=18 ; j++)
        {
            for(int i=1 ; i<=n ; i++)
            {
                  if(~lca[i][j-1])
                  {
                        int par = lca[i][j-1];
                        lca[i][j]=lca[par][j-1];
                  }
            }
        }

}

int LCA(int a, int b)
{
      if(level[a]>level[b]) swap(a,b);

      int d=level[b]-level[a];

      while(d>0)
      {
            int i=log2(d);

            b=lca[b][i];
            
            d-=(1<<i);

      }

      if(a==b)
            return a;
      for(int i=18 ; i>=0 ; i--)
      {
            if(lca[a][i]!=-1 && (lca[a][i]!=lca[b][i]))
                  a=lca[a][i], b=lca[b][i];
      }
      return lca[a][0];
}

void Solve()
{
         
        
        cin>>n;

        for(int i=1 ; i<n ; i++)
        {
            int x, y;
            cin>>x>>y;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        
        init();
        
         

     
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
