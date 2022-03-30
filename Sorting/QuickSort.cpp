/*
* @Author: Zakaria 
* @Date:   2022-03-30 17:50:08
* @Last Modified time: 2022-03-30 18:43:00
*/
/*
* @Author: Zakaria 
* @Date:   2022-03-30 17:51:06
* @Last Modified time: 2022-03-30 18:41:49
*/
/*
* @Author: Zakaria
* @Date:   2021-09-14 15:44:21
* @Last Modified time: 2022-03-30 01:59:18
*/

#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         200002
typedef long long ll;
using namespace std;

int cnt[MAX];
map<pair<int,int> , int >m;

void Solve()
{
         
         int n,k;
         cin>>n>>k;

         int a[n];

         for(int i=0 ; i<n ; i++)
            cin>>a[i],cnt[a[i]]++, m[{a[i],cnt[a[i]]}]=0;
         
         sort(a,a+n);

     
         for(int i=0 ; i<n ; i++)
         {

                 ll x=a[i];
                
                 ll pans=0;
                 while(x)
                 {
                     x/=2;
                     pans++;
                     cnt[x]++;
                     m[{x,cnt[x]}]+=m[{x, cnt[x]-1}]+pans;
            
                 }
                
         }
       
         int ans=1e9; 

         for(int i=1 ; i<=2e5 ; i++)
         {
             if(cnt[i]>=k)
             ans=min(ans, m[{i,k}]);
         }
         cout<<ans<<endl;

       




         
}


int main()
{

         ios::sync_with_stdio(false);
         cin.tie(0);

       

         int tt=1;
        // cin>>tt;
         while(tt--)
         {
             Solve();
         }
       
          
     return 0;


}
