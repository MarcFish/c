#include<stdio.h>
#include<vector>
#define N 101
#define Max 99999999
using namespace std;
struct E{
    int next;
    int c;
};
vector<E> edge[N];
bool mark[N];
int dis[N];
int main(void){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++) edge[i].clear();
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            E tmp;
            tmp.c=c;
            tmp.next=b;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        for(int i=1;i<=n;i++){
            dis[i]=-1;
            mark[i]=false;
        }
        dis[1]=0;
        mark[1]=true;
        int newp=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<edge[newp].size();j++){
                int t=edge[newp][j].next;
                int c=edge[newp][j].c;
                if(mark[t]==true) continue;
                if(dis[t]==-1||dis[t]>dis[newp]+c)
                dis[t]=dis[newp]+c;
            }
            int min=Max;
            for(int j=1;j<=n;j++){
                if(mark[j]==true) continue;
                if(dis[j]==-1) continue;
                if(dis[j]<min){
                    min=dis[j];
                    newp=j;
                }
            }
            mark[newp]=true;
        }
        printf("%d\n",dis[n]);
    }
    return 0;
}