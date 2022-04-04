/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-04-01 11:58:26
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
#define  MAX         200002
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
           Hash1[i] = (Hash1[i-1]*Base1 + (text[i-1]-'a'+1) ) % Mod1;
       }

}

ll GetHash1(int Left , int Right)
{
     ll HashValue = Hash1[Right] - (Hash1[Left-1]*Pow1[Right-Left+1])%Mod1 ; //Here pow is base^mod
      HashValue+=Mod1;
      HashValue%=Mod1;

      return HashValue;

}

ll PatternHash1(string pattern)
{
     ll x=0;
     for(int i=1 ; i<=pattern.size() ; i++)
      x = (x*Base1 + (pattern[i-1]-'a'+1))%Mod1;
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
           Hash2[i] = (Hash2[i-1]*Base2 + (text[i-1]-'a'+1) ) % Mod2;
       }

}

ll GetHash2(int Left , int Right)
{
      ll HashValue = Hash2[Right] - (Hash2[Left-1]*Pow2[Right-Left+1])%Mod2 ; //Here pow is base^mod
      HashValue+=Mod2;
      HashValue%=Mod2;

      return HashValue;

}

ll PatternHash2(string pattern)
{
     ll x=0;
     for(int i=1 ; i<=pattern.size() ; i++)
      x = (x*Base2 + (pattern[i-1]-'a'+1))%Mod2;
     return x;
}
int main()
{

          ios::sync_with_stdio(false);
          cin.tie(0);
          

          int t;
          cin>>t;
          while(t--)
          {
                set<pair<ll,ll> >st;
                int n,k;
                cin>>n>>k;

                string s;
                cin>>s;
                PowerGenerate1(n);
                PowerGenerate2(n);
                GenerateHash1(s);
                GenerateHash2(s);

                int j=k, i=1;
                
                while(j<=n)
                {
                    ll temp1=GetHash1(i,j);
                    ll temp2=GetHash2(i,j);
                    st.insert({temp1,temp2});
                    i++;
                    j++;
                }

                cout<<st.size()<<endl;
          }


         return 0;
}

//https://www.spoj.com/problems/ADACLEAN/ solve this using double hash