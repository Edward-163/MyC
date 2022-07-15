#include <stdio.h>
#include <string.h>

#define MAX(a,b)
int findSubstringInWraproundString(char * p){
    int len=strlen(p);
    int dp[26]={0};
    /// 子串相关的动态规划，一般状态的定义都是「以位置 ii 作为结尾的、符合要求的子串长度」
    /**
     zab
     dp[z]代表z结尾的str,显然只有一个满足题目要求,z和
     dp[a]代表a结尾的str,且a是可以接在z后面的,za和a,也就是2
     dp[b]代表b结尾的str,且b是可以接在a后面的,zab和ab和b,也就是3
     zaab
     上面会计算两次dp[a],答案的处理是dp[a]取max
     */
    int didx=p[0]-'a';//
    dp[didx]=1;
    int k=1;
    for(int a=1;a<len;a++){
        int i = (int)(p[a] - p[a - 1]);
        if (i == 1 || i == -25){
            k++;
        } else{
            k=1;
        }
            dp[p[a] - 'a'] = dp[p[a - 1] - 'a'] + 1;
    }

    int res=0;
    for(int a=0;a<26;a++){
        res+=dp[a];
    }
    return res;
}
int main(){
    printf("%d", findSubstringInWraproundString("zaab"));
    return 0;
}