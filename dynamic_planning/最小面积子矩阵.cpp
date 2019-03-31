#include <stdio.h>
#include <limits.h>
#define N 101
#define M 101
 
int martix[N][M];//输入的矩阵
int sum[M];//相邻的几行合并而成的一维数组
int m, n, k;
 
int Shortest(int sum[M])
{//求一维数组里面和不小于k的最短连续序列长度
    int from=0, to=0;
    int len=INT_MAX;
    int x=0;//from到to的序列和
    while(to<m)
    {
        while(x<k&&to<m)//序列和小于k那终点后移
        {
            x+=sum[to];
            to++;
        }
        while(x>=k&&from<to-1)//序列和不小于k那起点后移
        {
            if(to-from<len) len=to-from;//这是更短的序列，记下来
            x-=sum[from];
            from++;
        }
        if(from+1==to) return 1;//追尾了
    }
    return len;
}
 
int main()
{
    while(scanf("%d%d%d", &n, &m, &k)!=EOF)
    {
        for(int i=0; i<n; i++)//输入
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d", &martix[i][j]);
            }
        }
        int area=INT_MAX;//满足条件的最小面积，先假设是无穷大
        for(int i=0; i<n; i++)//从i行开始合并
        {
            for(int j=0; j<m; j++) sum[j]=0;//清空sum数组
            for(int k=i; k<n; k++)//合并从i行到k行
            {
                for(int j=0; j<m; j++) sum[j]+=martix[k][j];
                int len=Shortest(sum);
                if(len!=INT_MAX)
                {//如果面积比已有的最小面积还小，那就修改最小面积
                    if(len*(k-i+1)<area) area=len*(k-i+1);
                }
            }
        }
        if(area==INT_MAX) printf("-1\n");
        else printf("%d\n", area);
    }
    return 0;
}