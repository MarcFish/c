#include<stdio.h>
//快速排序
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;//从大到小
}
int quicksort(void){
    int buf[100];int n;
    sort(buf,buf+n,cmp);//默认从小到大
    return 0;
}
//冒泡排序
int maopao(void){
    int buf[100];int n;
    //输入
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            SWAP(*buf[j],*buf[j+1]);
        }
    }
    //输出
}
void SWAP(int*a,int*b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}