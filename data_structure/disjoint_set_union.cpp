#include<stdio.h>
#define N 100
int Tree[N];
void init(void){
    for(int i=1;i<=n;i++){
        Tree[i]=-1;
    }
}
int findroot(int x){
    if(Tree[x]==-1) return x;
    else {
        int tmp=findroot(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}
int main(void){
    a=findroot(a);
    b=findroot(b);
    if(a!=b) Tree[a]=b;
}