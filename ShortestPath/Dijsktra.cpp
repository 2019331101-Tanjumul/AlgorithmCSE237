#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;
const ll inf=LLONG_MAX;
vector<pair<ll,ll> >node[100003];
vector<ll>dis(100003,inf);
int n,m,w;
vector<ll>ans;
priority_queue< pair<ll,ll>, vector<pair<ll , ll> >, greater<pair<ll , ll > > > pq;
int parrent[100003];

void dijsktra(ll p)
{
        
     parrent[1]=1;
     pq.push({0,p}); 
     dis[p]=0;
     ans.push_back(p);
     while(!pq.empty())
     {
          ll curr_node=pq.top().second;
          ll curr_dis=pq.top().first;
           pq.pop();
           for( pair<ll ,ll> child: node[curr_node])
           {
           	   if(child.second+curr_dis<dis[child.first])
           	   {
                     
                     
                     parrent[child.first]=curr_node;

                     dis[child.first]=child.second+curr_dis;
                      
                     pq.push({dis[child.first],child.first});

           	   }
           }
          

     }      

}

void printparent(int k)
{

	
	if(k==1)
	     return ;
	 
	 printparent(parrent[k]);
     cout<<k<<" ";
	 
}


int main()
{
         
     
      cin>>n>>m;
      ll e,f,w;
      while(m--)
      {
          cin>>e>>f>>w;
          node[e].push_back({f,w});
          node[f].push_back({e,w});
      }

       dijsk(1);

      if(dis[n]==inf)
      	cout<<-1<<endl;
      else
      {
      	cout<<1<<" ";
      	printparent(n);
      }


      return 0;

}
