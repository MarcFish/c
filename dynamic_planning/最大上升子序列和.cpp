#include<stdio.h>
#include<string.h>
#define Max(a,b) a>b?a:b
int main(void){
    int n;int data[1001];int dp[1001];
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&data[i]);
            dp[i]=data[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(data[i]>data[j]){
                    dp[i]=Max(dp[i],dp[j]+data[i]);
                }
            }
        }
        int max=data[0];
        for(int i=1;i<=n;i++)
            max=Max(max,dp[i]);
        printf("%d",max);
    }
    return 0;
}