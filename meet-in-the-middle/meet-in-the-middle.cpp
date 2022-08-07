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
#define  MAX         500002
typedef long long ll;
using namespace std;

ll leftArray[MAX];
ll rightArray[MAX];
ll a[MAX];
vector<ll>v;


void CalcsubarrayLeft( int n, int c)
{
    for (int i=0; i<(1<<n); i++)
    {
        ll s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                s += a[j+c];
        leftArray[i] = s;
    }
}

void CalcsubarrayRight( int n, int c)
{
    for (int i=0; i<(1<<n); i++)
    {
        ll s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                s += a[j+c];
        rightArray[i] = s;
    }
}
void Solve()
{
         
         int n, m;
         cin>>n>>m;
         ll tot=0;
         for(int i=0 ; i<n ; i++)
            cin>>a[i], tot+=a[i];


         CalcsubarrayLeft(n/2, 0);
         CalcsubarrayRight(n - n/2, n/2);


         for(int i=0 ; i<(1<<(n-n/2)) ; i++)
            v.push_back(rightArray[i]);

          for(int i=0 ; i<v.size() ; i++)
            v[i]%=m;

         sort(v.begin(), v.end());
         
         ll ans=0;
         
         for(int i=0 ; i<(1<<n/2) ; i++)
         {
              leftArray[i]%=m;
              ll x = m - leftArray[i]-1;

              ll low=0, high=v.size()-1;
              ll temp=0;
              while(low<=high)
              {
                  ll mid=(low+high)/2;
                 
                  if(v[mid]<=x)
                    low=mid+1, temp=max(temp,v[mid]);
                  else
                    high=mid-1;
              }
              
              ans=max(ans, (leftArray[i]+temp)%m );
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
