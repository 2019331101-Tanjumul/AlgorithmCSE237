/*
* @Author: Zakaria 
* @Date:   2022-05-15 03:38:25
* @Last Modified time: 2022-05-15 03:38:48
*/
bool dfs(int p)
{
     
     vis[p]=1;
     for(int child:node[p])
     {
     	 if(vis[child]==0)
     	 {
     	 	 if(dfs(child)==1)
     	 	 	return 1;
     	 }
     	 else
     	 {
     	 	 if(vis[child]==1)
     	 	 	return 1;
     	 }
     }
     vis[p]=2;

     return 0;
}