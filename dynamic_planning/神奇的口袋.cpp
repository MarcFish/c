#include<stdio.h>
int main(void){
    int n;
    while(scanf("%d",&n)!=EOF){
        int dp[21][41];int v[21];
        for(int i=1;i<=n;i++){
            scanf("%d",&v[i]);
            dp[i][0]=1;
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
          for(int j=1;j<=40;j++)
          {
            dp[i][j]=dp[i-1][j];
            if(v[i]<=j)
              dp[i][j]+=dp[i-1][j-v[i]];
          }
        printf("%d",dp[n][40]);
    }
}