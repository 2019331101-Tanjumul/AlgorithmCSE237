/*
* @Author: Zakaria 
<<<<<<< HEAD
* @Date:   2022-03-30 17:50:40
* @Last Modified time: 2022-07-18 09:41:20
*/
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
=======
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-07-21 00:03:09
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


int n, m;
vector<pair<ll, ll> > v[MAX];
int take[MAX];
void Solve()
{
         
         cin>>n>>m;
       
         for(int i=0 ; i<m ; i++)
         { 
             int x, y, w;
             cin>>x>>y>>w;
             v[x].push_back({w, y});
             v[y].push_back({w, x});
         }

         priority_queue<pair<ll, ll>, vector<pair<ll,ll > >, greater<pair<ll, ll > > > pq;
         ll ans=0;
         pq.push({0, 1});

         while(pq.size())
         {
                
              pair<ll,ll>p=pq.top();
              pq.pop();

              if(take[p.s])
               continue;

              ans+=p.f;
              take[p.s]=1;

              for(auto i:v[p.s])
              {
                  if(!take[i.s])
                     pq.push({i});
              }

         }

         cout<<ans<<endl;




         
>>>>>>> 1a63812b78348a37c29a70432e56979c35ee835e
}

int main()
{
<<<<<<< HEAD
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}
=======
         
          ios::sync_with_stdio(false);
          cin.tie(0);
           
          int tt=1;
       //   cin>>tt;
          while(tt--)
          {
             Solve();
          }

          return 0;
        
}
>>>>>>> 1a63812b78348a37c29a70432e56979c35ee835e
