/*
* @Author: Zakaria 
* @Date:   2022-03-31 00:13:56
* @Last Modified time: 2022-03-31 00:13:56
*/
Why relaxation n-1 times?
: Doing k iterations of Bellman Ford only guarantees that 
dist[i] is the shortest path from s to i using at most k edges. 
Since the shortest path can need up to V - 1 edges, we need to do it V - 1 times.

  /*struct edge
{
   int a,b,cost;
};

const int inf=INT_MAX;
vector<edge>node;
int n,m,root_node;

void solve()
{
    vector<int>dis(n,inf);
    dis[root_node]=0;
    
    for(int i=0;i<n-1;i++)
    {
       for(int j=0;j<m;j++)
       {
          if(dis[node[j].a]<inf)
          {
             dis[node[j].b]=min(dis[node[j].b], dis[node[j].a]+node[j].cost);
          }
       }
    }

}*/
