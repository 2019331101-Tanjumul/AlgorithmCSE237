/*
* @Author: Zakaria 
* @Date:   2022-03-30 17:46:12
* @Last Modified time: 2022-03-30 21:08:43
*/
#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;
vector<int>node[200003];
int in[200003],dis[200003];
vector<int>ans;
int n,m;
void kahn(int p)
{
    priority_queue<int,vector<int>,greater<int> >q;
   
    for(int i=1;i<=n;i++)
      if(!in[i])
      q.push(i);

      while(!q.empty())
      {
          int temp=q.top();
         
          ans.push_back(temp);
          q.pop();
          for(auto i:node[temp])
          {
            
             in[i]--;             
             if(in[i]==0)
                q.push(i);
          }

      }
      
}
int main()
{
      
      
     
      ios::sync_with_stdio(false);
      cin.tie(0);
      
      
       cin>>n>>m;
       int p,q;
       while(m--)
       {
          cin>>p>>q;
          node[p].push_back(q);
          in[q]++;
       }
       
       kahn(n);
        
        if(ans.size()==n)
        {
          for(auto i:ans)
            cout<<i<<" ";
           cout<<endl; 
          
        }
        else
          cout<<"IMPOSSIBLE\n";


     
    

      return 0;
}