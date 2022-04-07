/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-04-07 22:17:30
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
ll Len1[51][MAX], Len2[51][MAX];

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
           Hash1[i]+=Mod1;
           Hash1[i]%=Mod1;
       }

}

ll GetHash1(int Left , int Right)
{
      ll HashValue = Hash1[Right] - (Hash1[Left-1]*Pow1[Right-Left+1])%Mod1 ; //Here pow is base^(right-lest+1)%mod
      HashValue+=Mod1;
      HashValue%=Mod1;

      return HashValue;

}

ll PatternHash1(string pattern)
{
     ll x=0;
     for(int i=1 ; i<=pattern.size() ; i++)
      x = (x*Base1 + (pattern[i-1]-'a'+1))%Mod1 , x+=Mod1, x%=Mod1;
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
           Hash2[i]+=Mod2;
           Hash2[i]%=Mod2;
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
      x = (x*Base2 + (pattern[i-1]-'a'+1))%Mod2 , x+=Mod2, x%=Mod2;
     return x;
}

void Work()
{       
         
          
          for(char c='a' ; c<='z' ; c++)
          {
               string temp1="";
               string temp2="";
              for(int i=1 ; i<=50 ; i++)
              {
                  temp1+=c;
                  temp2+=c;
                  Len1[c-'a'+1][i]=PatternHash1(temp1);
                  Len2[c-'a'+1][i]=PatternHash2(temp2);
              } 
          } 
}
int main()
{

          ios::sync_with_stdio(false);
          cin.tie(0);
          

          PowerGenerate1(100000);
          PowerGenerate2(100000);

          Work();
          
          int n;
          cin>>n;



          map<pair<ll,ll> ,ll>m;

          for(int i=0 ; i<n ; i++)
          {
             
             string s;
             cin>>s;
             ll Hash1=PatternHash1(s);
             ll Hash2=PatternHash2(s);
             m[{Hash1,Hash2}]=1;

          }

          int  q;
          cin>>q;
          ll Hash1=0,Hash2=0;
          ll CurrentLen=0;
          string temp="";
          while(q--) 
          {
               string s;
               char c;
               cin>>s;
               if(s=="SEED")
               {
                   cin>>c;
                   temp="";
                   temp+=c;
                   Hash1=PatternHash1(temp);
                   Hash2=PatternHash2(temp);
                   CurrentLen=1;
               }
               else if(s=="UPDATE")
               {
                   string pos;
                   cin>>pos;
                   if(pos=="LEFT")
                   {
                        char x;
                        int val;
                        cin>>x>>val;

                        ll pans1=( (Len1[x-'a'+1][val]*Pow1[CurrentLen])%Mod1 + Hash1)%Mod1;
                        Hash1=pans1;
                        ll pans2=( (Len2[x-'a'+1][val]*Pow2[CurrentLen])%Mod2 + Hash2)%Mod2;
                        Hash2=pans2;
                            
                        CurrentLen+=val;
                   }
                   else //update right
                   {
                        char x;
                        int val;
                        cin>>x>>val;
                        
                       
                         ll pans1 = ( (Hash1*Pow1[val])%Mod1 + Len1[x-'a'+1][val])%Mod1 ; 
                         Hash1=pans1;
                         ll pans2 = ( (Hash2*Pow2[val])%Mod2 + Len2[x-'a'+1][val])%Mod1 ;
                         Hash2=pans2;
                   
                         CurrentLen+=val;
                       
                   }

               }
               else
               {
                   if(m[{Hash1,Hash2}])
                   {
                      cout<<"Exist"<<endl;
                   }
                   else
                   {
                      cout<<"Doesn't Exist"<<endl;
                   }
               }
              

              
          }

         return 0;
}



/*

input :

10
xxyz
bbxxyzcc
cbd
bbb
ccbadd
abab
a
aabbaabbb
abb
bbaabbb
56
SEED a
UPDATE RIGHT a 1
UPDATE RIGHT b 1
CHECK
UPDATE RIGHT a 1
UPDATE RIGHT b 2
CHECK
SEED b
UPDATE RIGHT a 1 
UPDATE LEFT a 1
UPDATE RIGHT b 1
CHECK
SEED b
UPDATE RIGHT b 1
UPDATE LEFT a 1
CHECK 
SEED b
UPDATE LEFT b 2
CHECK
SEED b 
CHECK
UPDATE RIGHT b 2 
CHECK
SEED b 
CHECK
SEED b 
UPDATE RIGHT a 1
UPDATE LEFT a 2
UPDATE RIGHT b 2
CHECK
SEED a
UPDATE LEFT b 2
UPDATE RIGHT a 1
UPDATE RIGHT b 3
CHECK
UPDATE LEFT a 2
CHECK
SEED b 
CHECK
UPDATE RIGHT d 1
CHECK   
UPDATE LEFT c 1
CHECK
SEED b
UPDATE RIGHT a 1
UPDATE LEFT c 2
UPDATE RIGHT d 2
CHECK
SEED y
UPDATE LEFT x 2
UPDATE RIGHT z 1
CHECK
UPDATE RIGHT c 2
CHECK
UPDATE LEFT b 2
CHECK

Output:

Doesn't Exist
Doesn't Exist
Exist
Exist
Exist
Doesn't Exist
Exist
Doesn't Exist
Doesn't Exist
Exist
Exist
Doesn't Exist
Doesn't Exist
Exist
Exist
Exist
Doesn't Exist
Exist



*/