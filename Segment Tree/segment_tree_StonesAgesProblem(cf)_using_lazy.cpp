/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-15 03:25:16
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


ll a[MAX];
struct 
{
    ll prop=-1, sum;
} tree[MAX * 4];

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node].sum = a[b];
        tree[node].prop=-1;

        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
    tree[node].prop=-1;
}

void update(int node, int b, int e, int i, int j, ll x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) 
    {
        tree[node].sum = ((e - b + 1) * x);
        tree[node].prop = x; 
        return;
    }

    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    
    if(tree[node].prop != -1)
    { 
       tree[Left].prop = tree[Right].prop = tree[node].prop;

       tree[Left].sum = (mid-b+1) * tree[node].prop;
       
       tree[Right].sum = (e-mid)*tree[node].prop; 
       
       tree[node].prop = -1;
    }


    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

ll query(int node, int b, int e, int i, int j, ll carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum ;

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

     if(tree[node].prop != -1)
    { 
       tree[Left].prop = tree[Right].prop = tree[node].prop;

       tree[Left].sum = (mid-b+1) * tree[node].prop;
       
       tree[Right].sum = (e-mid)*tree[node].prop; 
       
       tree[node].prop = -1;
    }


    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);

    return p1 + p2;
}

void Solve()
{  
        
             int n,k;
             cin>>n>>k;
             
             for(int i=1 ; i<=n ; i++)
               cin>>a[i];

             init(1, 1, n);

             while(k--)
             {
                    int t;
                    cin>>t;

                    if(t==1)
                    {
                         ll l, r;
                         cin>>l>>r;
                         update(1, 1, n, l, l, r);
                    }
                    else
                    {
                         int x;
                         cin>>x;
                     
                         update(1, 1, n, 1, n, x);
                    }

                    cout<<query(1, 1, n, 1, n)<<endl;
             }

         
}

int main()
{
         
          ios::sync_with_stdio(false);
          cin.tie(0);
           
          int tt=1;
       //   cin>>tt;

          while(tt--)
          {
            
             Solve();
          }


          return 0;
        
}