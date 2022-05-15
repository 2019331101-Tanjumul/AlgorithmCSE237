/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-15 13:47:53
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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void Solve()
{  

         
            int n,q;
            cin>>n>>q;
            
            pbds tempx, tempy;
            map<int,int>mpx,mpy;
            for(int i=1 ; i<=q ; i++)
            {
                  int type;
                  cin>>type;

                  if(type==1)
                  {
                        int x,y;
                        cin>>x>>y;

                        tempx.insert(x);
                        tempy.insert(y);
                        mpx[x]++;
                        mpy[y]++;
                  }
                  else if(type==2)
                  {
                        int x,y;
                        cin>>x>>y;
                        mpx[x]--;
                        mpy[y]--;
                        if(!mpx[x])
                        tempx.erase(x);
                        if(!mpy[y])
                        tempy.erase(y);
                  }
                  else
                  {
                        int x1,y1,x2,y2;
                        cin>>x1>>y1>>x2>>y2;

                        if(x1<x2)
                            swap(x1,x2);
                        if(y1<y2)
                            swap(y1,y2);
                        
                        

                        if(tempx.order_of_key(x1+1) - tempx.order_of_key(x2)==(x1-x2+1))
                        {
                             cout<<"YES\n";
                             
                        }
                        else if(tempy.order_of_key(y1+1) - tempy.order_of_key(y2)==(y1-y2+1))
                        {
                             cout<<"YES\n";
                            
                        }
                        else
                        cout<<"NO\n";
                  }
            }
         

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