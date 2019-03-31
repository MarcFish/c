/*
    最长公共子序列
    dp[0][j]=0;
    dp[i][0]=0;
    dp[i][j]=dp[i-1][j-1]+1;(s1[i]==s2[j])
    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);(s1[i]!=s2[j])
*/
#include<stdio.h>
#include<string.h>
#define max(x,y) x>y?x:y
#define N 1000
int dp[N][N];
int main(void){
    char s1[N];char s2[N];
    while(scanf("%s%s",s1,s2)!=EOF){
        int l1=strlen(s1);
        int l2=strlen(s2);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(s1[i-1]!=s2[j-1]){
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j-1]+1;
                }
            }
        }
        printf("%d\n",dp[l1][l2]);
    }
    return 0;
}
