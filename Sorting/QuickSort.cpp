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
#include <ctime>
#include <cassert>
#include <complex>
#include <cstring>

#define  pb          push_back
#define  f           first
#define  s           second
#define  pi          acos(-1.0)
#define  LCM(a,b)    a*b/__gcd(a,b)
#define  GCD(a,b)    __gcd(a,b)
#define  mod         1000000007
#define  test        int t; cin>>t ;while(t--)
#define  sof         sizeof
#define  endl        '\n'
#define  MAX         1000002 

typedef long long ll;
using namespace std;

int partition(int a[], int low, int high)
{
      int pivot=a[high];

      int j,i=low;

      for(int j=low;j<high;j++)
      {
         if(a[j]<=pivot)
         {
            swap(a[i],a[j]);
            i++;
         }
      }
      swap(a[i],a[high]);

      return i;

}

void quick_sort(int a[], int low, int high)
{
     if(low<high)
     {
         int p=partition(a, low, high);// here p is index of pivot
         
         quick_sort(a,low,p-1);
         quick_sort(a,p+1,high);


     }
}
                    
int main()
{
    
      ios::sync_with_stdio(false);
      cin.tie(0); 
      
      int a[10]={5, 8, 9, 1, -2, 5, 10, 2, 4, 7};

      quick_sort(a,0,9);

      for(auto i:a)
        cout<<i<<" ";
      
 
return 0;           
    
              
}

