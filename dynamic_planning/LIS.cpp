/*
    最长递增子序列
    无序序列:a1...an
    F[1]=1;
    F[i]=max{1,F[j]+1|j<i&&aj<ai};
*/
#include<stdio.h>
#define max(x,y) x>y?x:y
#define N 1000
int list[N];
int dp[N];//保存以第i个值结尾的最长递增子序列的长度
int main(void){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
        scanf("%d",&list[i]);
        for(int i=1;i<=n;i++){
            int tmax=1;
            for(int j=1;j<i;j++){
                if(list[j]<list[i]){
                    tmax=max(tmax,dp[j]+1);
                }
            }
            dp[i]=tmax;
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        printf("%d",ans);
    }
}