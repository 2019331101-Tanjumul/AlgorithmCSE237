/*
#include<bits/stdc++.h>
using namespace std;

#define MX 999
#define ret return
#define ll int
#define pb push_back
#define loop(i,L,U) for( ll i=(ll)L ; i<U ; i++)
#define N 999
int n, a[N], b[N], f[N], answer=0;
///... // enter n and a[] from keyboard
int main() {
    int testcas;
    cin>>testcas;
    while(testcas--)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(f,0,sizeof f);
        answer=0;
        cin>>n;
        loop( i,1,n+1 ) cin>>a[i];
        for (int i=1; i<=n; i++)
        {
            f[i]=lower_bound(b+1, b+answer+1, a[i])-b;
           
            ///maximize(answer, f[i]);
            answer=max(answer, f[i]);
            b[f[i]]=a[i];
        }
      printf("LIS lenght - %d\n", answer);
        ////If you want to print the LIS:
        vector<int> T;
        int require = answer;
        for (int i=n; i>=1; i--)
            if (f[i]==require)
            {
                T.push_back(a[i]);
                require--;
            }
        // then print T with reversed order
        int i=T.size();
        while (i--)
            printf("%d ", T[i]);
        printf("\n");
    }
}*/
/*
9
1 15 1 10 13 1 1 19 8
5
6 7 1 2 32
8
7 8 9 1 2 3 4 5
7
6 7 9 5 7 20 1
9
1 15 1 10 13 1 1 19 8
16
1 2 3 4 5 3 4 6 7 1 2 3 8 5 6 10
*/

//#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <cassert>
#include <complex>
#include <cstring>
#include <chrono>
#include <random>
 
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  test        int t; cin>>t; while(t--)
#define  run_time    cerr << (float)clock() / (float)CLOCKS_PER_SEC << "s" << endl
#define  sof         sizeof
#define  endl        '\n'
#define  MAX          200005
 
typedef long long ll;
using namespace std;
 
int main()
{
 
       ios::sync_with_stdio(false);
       cin.tie(0); 
       
       
       int n;
       cin>>n;
       int a[n];
 
       for(int i=0;i<n;i++)
        cin>>a[i];
 
      vector<int>dp;
 
      dp.push_back(a[0]);
 
      for(int i=1;i<n;i++)
      {
          if(a[i]>dp[dp.size()-1])
            dp.push_back(a[i]);
          else
          {
              int ind=lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
 
              dp[ind]=a[i];
          }
 
      }
 
 
        cout<<dp.size()<<endl;

        for(auto i:dp)
          cout<<i<<" ";

 
 
 
     return 0;     
      
}