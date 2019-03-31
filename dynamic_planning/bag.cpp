/*
    dp[j]=max{dp[j-list[i].w]+v,dp[j]};
*/
#include<stdio.h>
#include<string.h>
#define INF 0x7ffffff
#define N 1000
#define max(x,y) x>y?x:y
struct E{
    int w;
    int v;
}list[N];
int dp[N];
int main(){
    int s,n;
    while(scanf("%d%d",&s,&n)!=EOF){
        for(int i=1;i<=n;i++)
        scanf("%d%d",&list[i].w,&list[i].v);
        memset(dp,0,sizeof(dp));//dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=s;j>=list[i].w;j--){
                dp[j]=max(dp[j],dp[j-list[i].w]+list[i].v);
            }
        }
        printf("%d\n",dp[s]);
    }
    return 0;
}