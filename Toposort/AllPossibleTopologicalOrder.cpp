/*
* @Author: Zakaria 
* @Date:   2022-03-07 09:23:15
* @Last Modified time: 2022-03-30 21:09:24
*/
#include <bits/stdc++.h>
#define  endl        '\n'
#define  sz      100005
typedef long long ll;
using namespace std;

vector<int>node[sz];
vector<int>ans;
int indegree[sz];
int vis[sz];
int n,m;
void topsort()
{

       for(int i=1 ; i<=n ; i++)
       {
           if(!indegree[i] && !vis[i])
           {
              for(auto adj:node[i])
                {
                    indegree[adj]--;
                }
           
              vis[i]=1;
              ans.push_back(i);

              topsort();
              
              vis[i]=0;
              ans.pop_back();

              for(auto adj : node[i])
                indegree[adj]++;

           }
       }


       if(ans.size()==n) //when array size equal to n then print
       {
          for(auto i:ans)
            cout<<i<<" ";
          cout<<endl;
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

      cout<<"All possible topsort is : \n";

      topsort();
      

      return 0;

}
