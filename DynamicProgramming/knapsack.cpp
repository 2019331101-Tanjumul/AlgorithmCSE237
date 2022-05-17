/*
* @Author: Zakaria 
* @Date:   2022-05-17 17:40:03
* @Last Modified time: 2022-05-17 17:40:10
*/
ll dp[102][MAX];
int n;
int a[MAX];

bool Can(int indx, int sum)
{
       
        if(dp[indx][sum]!=-1)
         return dp[indx][sum];

        if(indx>n) 
            return sum==0;
        if(sum<0)
            return 0;

        return dp[indx][sum]=(Can(indx+1, sum) | Can(indx+1,sum-a[indx]));
}