/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-07-17 20:39:26
*/
#include <bits/stdc++.h>
#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  endl        '\n'
typedef long long ll;
using namespace std;

const int N = 2e5 + 9;
int Table[N][20], a[N];

void Build(int n)
{
  
     for(int i=1 ; i<=n ; i++)
      Table[i][0]=a[i];

     for(int k=1 ; k<20 ; k++)
     {
         for(int i=1 ; i+(1<<k)-1<=n ; i++)
          Table[i][k]=min(Table[i][k-1], Table[i+(1<<(k-1))][k-1]);
     }
   
}

int Query(int l, int r)
{
     int k = 31 - __builtin_clz(r-l+1);
     return min(Table[l][k], Table[r-(1<<k)+1][k]);
}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);

          int n;
          cin>>n;

          for(int i=1 ; i<=n ; i++)
            cin>>a[i];
          Build(n);

          cout<<Query(1,n);

          return 0;
        
}

/*
#include<bits/stdc++.h>
using namespace std;
#define Max 10000005
int ST[24][Max];
int A[Max];
void Compute_ST(int N)
{
    for (int i=0;i<N;i++)ST[0][i] = i;
    for (int k = 1;(1 << k)<N; k++)
    {
        cout<<k<<" =>\n";
        for (int i=0;i+(1<<k)<=N;i++)
        {
            int x = ST[k-1][i];
            int y = ST[k-1][i+(1<<k-1)];

            cout<<i<<" "<<i+(1<<k-1)<<endl;
            
            ST[k][i]=A[x]<=A[y]?x:y;
            cout<<"min is "<<ST[k][i]<<endl;
        }
    }
}
 
int RMQ(int i, int j)
{
    int k = log2(j-i);
    int x = ST[k][i];
    int y = ST[k][j-(1<<k)+1];
    return A[x] <= A[y] ? x : y;
}
 
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    Compute_ST(N);
    int Q;
    cin>>Q;
    while(Q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<A[RMQ(x,y)]<<endl;
    }
    return 0;
}*/