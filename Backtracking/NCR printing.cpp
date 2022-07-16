/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-07-16 12:45:24
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
#define  MAX         100002
typedef long long ll;
using namespace std;

int n,m;

vector<int>order;
int vis[MAX];

void Backtrack(int x)
{
        if(order.size()==m)
        {
            for(auto i:order)
               cout<<i<<" ";
            cout<<endl;
            return ;
        }

        for(int i=x+1 ; i<=n ; i++)
        {
              if(vis[i])
               continue;

              order.push_back(i);
              vis[i]=1;
              Backtrack(order.back());
              order.pop_back();
              vis[i]=0;
        }
}
void Solve()
{  
         
         cin>>n>>m;
         Backtrack(0);

}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
           
          int tt=1;
        //  cin>>tt;
          while(tt--)
          {
             Solve();
          }


          return 0;
        
}