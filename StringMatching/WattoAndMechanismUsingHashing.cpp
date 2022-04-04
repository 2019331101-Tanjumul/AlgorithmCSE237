/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-04-03 20:56:03
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
#define  MAX         600002
typedef long long ll;
using namespace std;

ll Hash1[MAX], Pow1[MAX];
const ll Base1=1231;
const ll Mod1=1e9+7;

void PowerGenerate1(ll n)
{
     Pow1[0]=1;
     for(int i=1 ; i<=n ; i++)
     {
       Pow1[i]=(Pow1[i-1]*Base1)%Mod1;
     }

}

void GenerateHash1(string text)
{
       Hash1[0]=0;

       for(int i=1 ; i<=text.size() ; i++) //1 base indexing for string
       {
           Hash1[i] = ( (Hash1[i-1]*Base1)%Mod1 + (text[i-1]-'a'+1) ) % Mod1;
       }

}

ll GetHash1(int Left , int Right)
{
     ll HashValue = (Hash1[Right] - (Hash1[Left-1]*Pow1[Right-Left+1])%Mod1)%Mod1 ; //Here pow is base^mod
      HashValue+=Mod1;
      HashValue%=Mod1;

      return HashValue;

}

ll PatternHash1(string pattern)
{
     ll x=0;
     for(int i=1 ; i<=pattern.size() ; i++)
      x = ( (x*Base1)%Mod1 + (pattern[i-1]-'a'+1))%Mod1;
     return x;
}


ll Hash2[MAX], Pow2[MAX];
const ll Base2=1567;
const ll Mod2=1e9+9;

void PowerGenerate2(ll n)
{
     Pow2[0]=1;
     for(int i=1 ; i<=n ; i++)
     {
       Pow2[i]=(Pow2[i-1]*Base2)%Mod2;
     }

}

void GenerateHash2(string text)
{
       Hash2[0]=0;

       for(int i=1 ; i<=text.size() ; i++) //1 base indexing for string
       {
           Hash2[i] = ( (Hash2[i-1]*Base2)%Mod2 + (text[i-1]-'a'+1) ) % Mod2;
       }

}

ll GetHash2(int Left , int Right)
{
      ll HashValue = (Hash2[Right] - (Hash2[Left-1]*Pow2[Right-Left+1])%Mod2)%Mod2 ; //Here pow is base^mod
      HashValue+=Mod2;
      HashValue%=Mod2;

      return HashValue;

}

ll PatternHash2(string pattern)
{
     ll x=0;
     for(int i=1 ; i<=pattern.size() ; i++)
      x = ( (x*Base2)%Mod2 + (pattern[i-1]-'a'+1))%Mod2;
     return x;
}
void Solve()
{
         
          int n,m;
          cin>>n>>m;
          map< pair<ll,ll>, int > st;
          for(int i=0 ; i<n ; i++)
          {
              string s;
              cin>>s;
              PowerGenerate1(s.size());
              PowerGenerate2(s.size());
              ll temp1=PatternHash1(s);
              ll temp2=PatternHash2(s);
              st[{temp1,temp2}]=1;
          }

   
         
          for(int i=1 ; i<=m ; i++)
          {
               string s;
               cin>>s;
               
               ll Hash1=PatternHash1(s);
               ll Hash2=PatternHash2(s);

               string text=s;
               int len=s.size();
               bool ok=0;
               for(int i=1 ; i<=len ; i++)
               {
                    ll Hash1_A= ( (Hash1+Mod1)%Mod1 + ( ('a' - s[i-1])*Pow1[len-i])%Mod1 )%Mod1;
                    Hash1_A+=Mod1;
                    Hash1_A%=Mod1;

                    ll Hash1_B= ( (Hash1+Mod1)%Mod1 + ( ('b' - s[i-1])*Pow1[len-i])%Mod1 )%Mod1;
                    Hash1_B+=Mod1;
                    Hash1_B%=Mod1;

                    ll Hash1_C= ( (Hash1+Mod1)%Mod1 + ( ('c' - s[i-1])*Pow1[len-i])%Mod1 )%Mod1;
                    Hash1_C+=Mod1;
                    Hash1_C%=Mod1;
                    
                    ll Hash2_A= ( (Hash2+Mod2)%Mod2 + ( ('a' - s[i-1])*Pow2[len-i])%Mod2 )%Mod2;
                    Hash2_A+=Mod2;
                    Hash2_A%=Mod2;

                    ll Hash2_B= ( (Hash2+Mod2)%Mod2 + ( ('b' - s[i-1])*Pow2[len-i])%Mod2 )%Mod2;
                    Hash2_B+=Mod2;
                    Hash2_B%=Mod2;

                    ll Hash2_C= ( (Hash2+Mod2)%Mod2 + ( ('c' - s[i-1])*Pow2[len-i])%Mod2 )%Mod2;
                    Hash2_C+=Mod2;
                    Hash2_C%=Mod2;
                   
                
                    if(s[i-1]=='a')
                    {
                       if(st[{Hash1_B, Hash2_B}])
                         ok=1;
                       if(st[{Hash1_C, Hash2_C}])
                         ok=1;
                    }
                    if(s[i-1]=='b')
                    {
                        if(st[{Hash1_A, Hash2_A}])
                         ok=1;
                        if(st[{Hash1_C, Hash2_C}])
                         ok=1;
                    }
                    if(s[i-1]=='c')
                    {
                        if(st[{Hash1_A, Hash2_A}])
                         ok=1;
                        if(st[{Hash1_B, Hash2_B}])
                         ok=1;
                    }

               }

               if(ok)
                  cout<<"YES\n";
               else
                  cout<<"NO\n";

          }
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



//https://codeforces.com/contest/514/problem/C