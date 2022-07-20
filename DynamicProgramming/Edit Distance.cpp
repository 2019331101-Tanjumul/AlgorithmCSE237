
/*
* @Author: Zakaria 
* @Date:   2022-04-01 01:08:32
* @Last Modified time: 2022-07-17 13:41:13
*/
int dp[5001][5001];
memset(dp, -1 ,sizeof(dp));
solve(0,0, s1, s2);

int solve(int i, int j, string& s1, string& s2)
{
    if(i == s1.length() || j == s2.length())
        return max((int)s2.length() - j, (int)s1.length() - i);
 
    if(dp[i][j] != -1)
        return dp[i][j];
 
    int ans;
    if(s1[i] == s2[j]){
        ans = solve(i+1,j+1,s1,s2);
    }
    else{
        int op1 = 1 + solve(i,j+1,s1,s2);//add
        int op2 = 1 + solve(i+1,j,s1,s2);//remove
        int op3 = 1 + solve(i+1,j+1,s1,s2);//replace
        ans = min(op1,min(op2,op3));
    }
    return dp[i][j] = ans;
}

