/*
* @Author: Zakaria 
* @Date:   2022-03-30 17:48:41
* @Last Modified time: 2022-03-31 12:29:01
*/
#include<bits/stdc++.h>
#define pb       push_back
#define pi       acos(-1.0)
#define mod      1000000007
#define test     int t; cin>>t ;while(t--)
typedef long long ll;
using namespace std;                                                           
const ll inf=LLONG_MAX;

vector<int>node[10003];

int lowtime[10003],intime[10003],vis[10003];

set<int>cut_vertex;

int timer;

void IS_CUTPOINT(int x)
{
    cut_vertex.insert(x);
}

void dfs(int p, int parent)
{   
     
       intime[p]=lowtime[p]=timer;
       timer++;
       int children=0;
       vis[p]=1;

       for(int child:node[p])
       {
           
           if(child==parent)
           continue;

           if(vis[child])
           {
              lowtime[p]=min(lowtime[p], intime[child]); // node - child is a back edge
           }

           else
           {
               // node -  child is a forward edge 
               dfs(child,p);

               if(lowtime[child] >= intime[p] && parent!=-1)
                IS_CUTPOINT(p);

               lowtime[p] = min(lowtime[p] , lowtime[child]);
               children++;
           }

       }

       if(parent == -1 && children>1)//for root
          IS_CUTPOINT(p);
}



int main()
{
      
    ios::sync_with_stdio(false);
    cin.tie(0);
     
     

     int n,m;
     cin>>n>>m;
     while(m--)
     {
        int p,q;
        cin>>p>>q;
        node[p].push_back(q);
        node[q].push_back(p);
     }

     dfs(1,-1);
     
     for(auto i:cut_vertex)
     cout<< i <<" is a cut vertex"<<endl;
     
      
     return 0;
       
}