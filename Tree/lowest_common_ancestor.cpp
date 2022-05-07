/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-07 20:16:30
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
vector<int> adj[MAX];
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
            }

          preprocess(0);

         
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



      