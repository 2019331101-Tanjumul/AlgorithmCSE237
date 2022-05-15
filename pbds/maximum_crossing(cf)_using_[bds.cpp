/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-15 11:20:56
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

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void Solve()
{  

         
            int n;
            cin>>n;

            pbds st, pans;
            int a[n+1];
            map<int,int>before, m;
            for(int i=1 ; i<=n ; i++)
            {
                 cin>>a[i];
                 m[a[i]]++;
                 st.insert(a[i]);
            }

            ll ans=0;

       

            for(int i=1 ; i<=n ; i++)
            {
                  before[a[i]]++;
                  ans=ans+st.order_of_key(a[i]);
                  ans+=m[a[i]];
                  ans-=before[a[i]];
                  ans-=pans.order_of_key(a[i]);
                  pans.insert(a[i]);

            }
            cout<<ans<<endl;

         

}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
           
          int tt=1;
          cin>>tt;
          while(tt--)
          {
             Solve();
          }


          return 0;
        
}