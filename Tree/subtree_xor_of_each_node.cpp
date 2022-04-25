/*
* @Author: Zakaria 
* @Date:   2022-04-25 00:56:21
* @Last Modified time: 2022-04-25 01:13:38
*/
ll dfs(int p)
{
     vis[p]=1;
     dis[p]=a[p];
     ll cur=a[p];
     for(auto i:node[p])
     {
         if(vis[i]==0)
         {
             cur^=dfs(i);
 
         }
     }
     dis[p]=cur;
     return cur;
 
}
