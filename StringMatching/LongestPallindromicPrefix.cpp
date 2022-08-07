/*
* @Author: Zakaria 
* @Date:   2022-06-16 15:16:33
* @Last Modified time: 2022-06-16 15:16:42
*/
string LongestPalindromicPrefix(string str)
{
 
    string temp = str + '?';
 
    reverse(str.begin(), str.end());
    temp += str;

    int n = temp.length();
 
    int lps[n];
 
    fill(lps, lps + n, 0);
 
    for (int i = 1; i < n; i++) {
        int len = lps[i - 1];
        while (len > 0
               && temp[len] != temp[i]) {
            len = lps[len - 1];
        }
        if (temp[i] == temp[len]) {
            len++;
        }
        lps[i] = len;
    }

    return temp.substr(0, lps[n - 1]);
}