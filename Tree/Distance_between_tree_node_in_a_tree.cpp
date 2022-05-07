/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-07 20:37:36
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
#define  MAX         300002
typedef long long ll;
using namespace std;
const ll mod=1e9+7;

int n, l;
vector<int> adj[MAX],node[MAX];
int vis[MAX],dis[MAX];
int timer;
vector<int> tin, tout;
vector<vector<int>> up;


void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

void dfs_dis(int parent)
{
     vis[parent]=1;

     for(auto i:node[parent])
     {
         if(!vis[i])
         {
              dis[i]=dis[parent]+1;
              dfs_dis(i);
         }
     }
}

int res(int a, int b , int c)
{
        int temp=dis[a]+dis[b]-2*dis[lca(a,b)];
        int x=lca(a,b);

        int pans=dis[c]+dis[x]-2*dis[lca(x,c)];

        return pans+temp;
}

void Solve()
{ 

           
           cin>>n;

           int q;
           cin>>q;

           for(int i=1 ; i<n ; i++)
            { 
                   int u,v;
                   cin>>u>>v;
                   u--;
                   v--;
                   adj[u].push_back(v);
                   adj[v].push_back(u);
                   node[u].push_back(v);
                   node[v].push_back(u);
            }

          preprocess(0);

          dfs_dis(0);



           while(q--)
           {
                 int a,b,c;

                 cin>>a>>b>>c;
                 a--,b--,c--;
                 int ans=n+1;
                 ans=min(ans, res(a,b,c));
                 ans=min(ans, res(a,c,b));
                 ans=min(ans, res(b,c,a));
                 cout<<ans<<endl;
           }
}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
          

          int tt=1;

        //  cin>>tt;
          while(tt--)
            Solve();
      

          return 0;
        
}



      