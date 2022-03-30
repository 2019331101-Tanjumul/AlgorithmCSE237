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
#include <iomanip>
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

vector<int>node[10000],transpose_node[10000];
int visit[10000],out_time[10000],in_time[10000];
vector<int>order;//by out_time we can sort by out_time but stack/vector reduce complexity 
vector<int>SCC;
int timer;

void dfs(int x)
{
      visit[x]=1;
      in_time[x]=++timer;

      for(auto i:node[x])
            if(!visit[i])
                  dfs(i);
      
      out_time[x]=++timer;
      order.push_back(x); // all the child of this node (X) already visited 
}

void dfs_for_scc(int x) //This dfs for find scc 
{
      visit[x]=1;
      SCC.push_back(x);

      for(auto child:transpose_node[x])
            if(!visit[child])
                  dfs_for_scc(child);
}

int main()
{
     
      ios::sync_with_stdio(false);
      cin.tie(0); 
      
      int n,m;
      cin>>n>>m;

      int a,b;
      while(m--)
      {
            cin>>a>>b;
            node[a].push_back(b);
            transpose_node[b].push_back(a); //to find scc we need to run dfs is transpose graph of main graph
      }
      
      for(int i=1 ;i<=n ;i++)
         if(visit[i]==0) dfs(i); 

      for(int i=1 ;i<=n ;i++) visit[i]=0;
  
      cout<<"here is node list by order of out time\n";
      for(int i=n-1 ;i>=0 ; i--)
            cout<<order[i]<<" out time is -> "<<out_time[order[i]]<<endl;

      for(int i=n-1 ; i>=0 ; i--)
      {
            if(visit[order[i]]==0)  //order[i] is by largest outime 
            {
               SCC.clear(); //previous SCC cleard 
               dfs_for_scc(order[i]); // for finding scc we run dfs in transpose graph 
               
               cout<<"Strongly Connected Components are \n";
               for(auto child:SCC)
                  cout<<child<<" ";
               cout<<endl;
            }
      }


return 0;           
              
}

