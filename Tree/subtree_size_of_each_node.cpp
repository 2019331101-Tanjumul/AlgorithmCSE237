#include<bits/stdc++.h>
#define pb       push_back
#define f        first
#define s        second
#define pi       acos(-1.0)
#define test     int t; cin>>t; while(t--)
typedef long long ll;
using namespace std;
int dis[100005],vis[100005];
vector<int>node[100005];
int n,p,q;
int dfs(int p)
{

	vis[p]=1;
 	int cur=1;
	dis[p]=1;
	for(auto i:node[p])
	{
		 if(!vis[i])
		 	cur+=dfs(i);
	}
	dis[p]=cur;
	return cur;// return current size means child size;
}


int main()
{

         ios::sync_with_stdio(false);
         cin.tie(0);
         
         
         cin>>n;
         int m=n-1;
         while(m--)
         {
            cin>>p>>q;
            node[p].push_back(q);
            node[q].push_back(p);
         }        

         dfs(1);

         for(int i=1;i<=n;i++)
         cout<<dis[i]<<" ";

          
     return 0;


}
