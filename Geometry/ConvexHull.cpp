/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-12 13:22:34
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

struct point
{
      int x,y;
      
      point(){}
      point(int _x, int _y) : x(_x), y(_y) {}
      
     

      bool operator < (point &pt)
      {
            if(pt.x == x) 
               return y < pt.y;
            else
               return x < pt.x;
      }

      bool operator == (point &pt) {  // operator overloading for unique() func
      return (x == pt.x && y == pt.y);
   }

};


bool cw(point a, point b, point c) {  // clock wise

   return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
bool ccw(point a, point b, point c) {   // counter clock wise

   return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

void Solve()
{
         
       

       int n;
       cin>>n;
       vector<point>pt;

       for(int i=0 ; i<n ; i++)
       {
           int x,y;
           cin>>x>>y;
           pt.push_back(point(x,y));
       }
    ;

      sort(pt.begin(), pt.end());

      
      vector<point>res;

      for(int i=0 ; i<n ; i++)
      {
          while(res.size()>=2 &&  ccw(res[res.size()-2], res[res.size()-1], pt[i]))
            res.pop_back();
          res.push_back(pt[i]);
      }

      vector<point>res2;
      reverse(pt.begin(), pt.end());

      for(int i=0 ; i<n ; i++)
      {
          while(res2.size()>=2 &&  ccw(res2[res2.size()-2], res2[res2.size()-1], pt[i]))
            res2.pop_back();
          res2.push_back(pt[i]);
      }
      
      vector<point>hull;

      for(auto i:res)
         hull.push_back(i);
      for(auto i:res2)
         hull.push_back(i);
      
      sort(hull.begin(), hull.end());

      hull.resize(unique(hull.begin(), hull.end()) - hull.begin());

      for(auto i:hull)
         cout<<i.x<<" "<<i.y<<endl;



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