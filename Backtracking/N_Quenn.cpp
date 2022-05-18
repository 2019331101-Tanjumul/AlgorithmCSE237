/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-05-19 00:40:18
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

const int n=7;

bool Safe(int Board[n+1][n+1], int row, int column)
{
       
       for(int j=1 ; j<=column ; j++)
       {
            if(Board[row][j])
                return 0;        
       }

       for(int i=1 ; i<=row ; i++)
       {
            if(Board[i][column])
                return 0;
       }

       for(int i=row , j=column ; i>=1 && j>=1 ; i--,j--)
       {
            if(Board[i][j])
                return 0;
       }

      
     
        for(int i=row , j=column ; j>=1 && i<=n ; i++,j--)
       {
           if(Board[i][j])
            return 0;
       }

       return 1;
}

bool Backtrack(int Board[n+1][n+1], int column)
{
      if(column>=n+1)
        return 1;

      for(int row=1 ; row<=n ; row++)
      {
            if(Safe(Board, row, column))
            {
                   Board[row][column]=1;

                   if(Backtrack(Board, column+1))
                   {
                         return 1;
                   }

                   Board[row][column]=0;
            }
      }
      
      return 0;

}


void Solve()
{  

           
            int Board[n+1][n+1];
            memset(Board, 0, sizeof(Board));


            if(!Backtrack(Board, 1))
            {
                 cout<<"Not posible\n";
            }
            else
            {
                 for(int i=1  ; i<=n ; i++)
                 {
                     for(int j=1 ; j<=n ; j++)
                        cout<<Board[i][j]<<" ";
                     cout<<endl;
                 }
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