/*
    dp[0]=a[0];
    dp[i]=max{dp[i-1]+a[i],a[i]}
*/
#include<stdio.h>
#define N 1000000
#define max(a,b) a>b?a:b
int dp[N];
int a[N];
long long maxx;
int main(void)
{
    int n ;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        dp[0] = a[0];
        maxx = a[0];
        for(int i=1;i<n;i++){
            dp[i] = max(dp[i-1]+a[i],a[i]);
            if(maxx<dp[i]){
                maxx = dp[i];
            }
        }
        printf("%d",maxx);
    }
   return 0;
}