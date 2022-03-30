/*
* @Author: Zakaria 
* @Date:   2022-03-30 20:31:52
* @Last Modified time: 2022-03-30 20:32:36
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <complex>
#include <cstring>

#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  test        int t; cin>>t ;while(t--)
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         2000002 

typedef long long ll;
using namespace std;

int n,m;
int parent[MAX],Rank[MAX];
void Init(int n)
{
          for(int i=0 ;i<=n ;i++)
            Rank[i]=1,parent[i]=i;
}

int Find_parent(int v) {
    if (v == parent[v]) {
        return v;
        }
    return parent[v] = Find_parent(parent[v]);
}
 
void Union(int a, int b) {
    a = Find_parent(a);
    b = Find_parent(b);
    if (a != b) {
        if (Rank[a] > Rank[b]) {
            swap (a, b);
                }
        parent[a] = b;
        Rank[b] += Rank[a];
    }
}

int main()
{
        
        
        cin>>n>>m;
        
        init(n);


        for(int i=1 ; i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            union_sets(u,v);
        }

        for(int i=1 ;i<=n; i++)
            cout<<find_parent(i)<<" ";
        cout<<endl;
        
         for(int i=1 ; i<=n ; i++)
            cout<<Rank[i]<<" ";

        

        

return 0;

} 

/*struct dsu{
    int n;
    vector<int>par, rnk;
    void init(int _n){
        n = _n;
        par.resize(n+1), rnk.resize(n+1, 0);
        for(int i=1; i<=n; i++) par[i] = i;
    }
    bool unite(int u, int v){
        u = faind(u), v = faind(v);
        if(u==v) return false;
        if(rnk[u]>rnk[v]) swap(u,v);
        par[u] = v;
        if(rnk[u]==rnk[v]) rnk[v]++;
        return true;
    }
    int faind(int u){
        if(u==par[u]) return u;
        return par[u] = faind(par[u]);
    }
};
 */