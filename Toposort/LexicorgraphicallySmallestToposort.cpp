/*
* @Author: Zakaria 
* @Date:   2022-03-07 09:23:15
* @Last Modified time: 2022-03-30 21:09:04
*/
#include <bits/stdc++.h>
#define  endl        '\n'
#define  sz      1000005
typedef long long ll;
using namespace std;

vector<int>node[sz];
vector<int>ans;
int indegree[sz];
int n,m;
void topsort()
{

	   priority_queue<int, vector<int> , greater<int> >q;

	   for(int i=1 ; i<=n ; i++)
	   {
	   	   if(!indegree[i])
	   	   	q.push(i);
	   }
       while(q.size())
       {
       	   int x=q.top();
           ans.push_back(x);
       	   q.pop();

       	   for(auto i:node[x])
       	   {
       	   	    indegree[i]--;
       	   	    if(!indegree[i])
       	   	    	q.push(i);
       	   }
       }


}

int main()
{
      ios::sync_with_stdio(false);
      cin.tie(0);

      
      cin>>n>>m;

      for(int i=1 ; i<=m ; i++)
      {
      	     int x,y;
      	     cin>>x>>y;
      	     node[x].push_back(y);
      	     indegree[y]++;
      }

      topsort();

      if(ans.size()==n)
      {
      	  for(auto i:ans)
      	  cout<<i<<" ";
      	   cout<<endl;
      }
      else
      	cout<<"Sandro fails.\n";
      
      

      return 0;

}
