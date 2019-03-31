#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
int data[101][101];
int dp[101];
int n;
int sum_vector(int x[]){
    int dpx[n];
    memset(dpx,0,n);
    dpx[0]=x[0];
    int maxx=x[0];
    for(int i=1;i<n;i++){
        dpx[i]=max(dpx[i-1]+x[i],x[i]);
        if(dpx[i]>maxx)
            maxx=dpx[i];
    }
    return maxx;
}
int main(void){
    while(scanf("%d",&n)!=EOF){
        int Max=-99999999;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&data[i][j]);
        for(int i=0;i<n;i++){
            memset(dp,0,sizeof(dp));
            for(int j=i;j<n;j++){
                for(int k=0;k<n;k++){
                    dp[k]=dp[k]+data[j][k];
                }
                Max=max(sum_vector(dp),Max);
            }
        }
        printf("%d",Max);
    }
    return 0;
}