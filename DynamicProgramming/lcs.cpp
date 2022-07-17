/*
* @Author: Zakaria 
* @Date:   2022-07-17 12:43:38
* @Last Modified time: 2022-07-17 12:52:11
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
#define  MAX         5000002
typedef long long ll;
using namespace std;


void Solve()
{     
        
        string s, t;
        cin>>s>>t;

        int n=s.size(), m=t.size();
        s='*'+s;
        t='*'+t;
        int dp[n+1][m+1];
        memset(dp, 0 ,sizeof(dp));

        for(int i=1 ; i<=n ; i++)
        {
        	for(int j=1 ; j<=m ; j++)
        	{
                 if(s[i]==t[j])        // 1+lcs(i-1,j-1);
                 {
                 	dp[i][j]=1+dp[i-1][j-1];
                 }
                 else
                 	dp[i][j]=max(dp[i-1][j], dp[i][j-1]); //max(lcs(i-1, j), lcs(i, j-1))
        	}
        }
        cout<<dp[n][m]<<endl;
        string ans="";
        int left=n, right=m;
        while(left>=1 && right>=1)
        {
            if(dp[left][right]>dp[left-1][right] && dp[left][right]>dp[left][right-1])
            	ans+=s[left], left--, right--;
            else
            {
            	if(dp[left][right]==dp[left-1][right])
            		left--;
            	else if(dp[left][right]==dp[left][right-1])
            		right--;
            }
        }
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
}
int main()
{     
      
      ios::sync_with_stdio(false);
      cin.tie(0);
      
      int tt=1;
      //cin>>tt;
      while(tt--)
      {
           
            Solve();
      }
      
      return 0;
      
}     