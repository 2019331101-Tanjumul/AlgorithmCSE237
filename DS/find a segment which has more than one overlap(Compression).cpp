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
#define  MAX         5000002
typedef long long ll;
using namespace std;



void Solve()
{
         
        int n;
        cin>>n;

        vector<pair<int, int> > v;
        set<int>st;
        for(int i=0 ; i<n ; i++)
        {
             int x, y;
             cin>>x>>y;
             v.push_back({x,y});
            
             st.insert(x);
             st.insert(y);
             st.insert(y+1);
        }

        int cnt=0;
        map<int, int> m;

        for(auto i:st)
            m[i]=++cnt;

        int cum[cnt+4], exist[cnt+4];
        memset(cum, 0, sizeof(cum));
        memset(exist, 0, sizeof(exist));

       for(auto i:v)
       {
          
          cum[m[i.f]]++;
          cum[m[i.s]+1]--;
       }

       for(int i=1 ; i<=cnt ; i++)
         cum[i]+=cum[i-1];
       
       
       for(int i=1 ; i<=cnt ; i++)
       {
          if(cum[i]<=1)
              exist[i]=i;
          else
            exist[i]=exist[i-1];
       }

       
       for(int i=0 ; i<n ; i++)
       {
            if(exist[m[v[i].s]]<m[v[i].f])
            {
                 cout<<i+1<<endl;
                 return ;
            }
       }
       cout<<-1<<endl;
      
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
