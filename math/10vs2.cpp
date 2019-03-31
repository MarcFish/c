#include<stdio.h>
#include<string>
#define Max 4000
using namespace std;
int conversion(int d[],int data[],int n,int x,int y){
    int size=0;
    for(int i=0;i<n;){
        int k=0;
        for(int j=i;j<n;j++){
            int t=(d[j]+k*x)%y; 
            d[j]=(d[j]+k*x)/y;
            k=t;
        }
        data[size++]=k;
        while(d[i]==0) i++;
    }
    return size;
}
int main(void){
    char s[Max];
    int d[Max],data[Max];
    int length;
    while(scanf("%s",s)!=EOF){
        for(length=0;s[length]!='\0';length++)
            d[length]=s[length]-'0';
        length;
        int n=conversion(d,data,length,10,2);
        int start;
        for(start=0;data[start]==0;start++);
        for(int i=start;i<n;i++)
            data[i-start]=data[i];
        n=conversion(data,d,n-start,2,10);
        for(int i=n-1;i>=0;i--)
            printf("%d",d[i]);
    }
    return 0;
}