#include<stdio.h>
#include<math.h>
#include<string.h>
bool judge(int x){
    if(x<=1) return false;
    int bound=(int)sqrt(x)+1;
    for(int i=2;i<bound;i++){
        if(x%i==0) return false;
    }
    return true;
}
int prime[10000];
int primesize;
bool mark[10001];
void init(){
    memset(mark,0,sizeof(mark));
    primesize=0;
    for(int i=2;i<10001;i++){
        if(mark[i]) continue;
        prime[primesize++]=i;
        for(int j=i*i;j<10001;j=j+i)
            mark[j]=true;
    }
    return;
}