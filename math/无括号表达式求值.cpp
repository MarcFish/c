#include<stdio.h>
#include<string>
#define Max 1000
int main(void){
    char op;
    double d[Max];
    double t;
    while(scanf("%lf",&t)!=EOF){
        d[0]=0;
        d[1]=t;
        int i=1;
        while(scanf("%c",&op)!=EOF&&op!='\n'){
            scanf("%lf",&t);
            if(op=='+') d[++i]=t;
            else if(op=='-') d[++i]=-t;
            else if(op=='*') d[i]=d[i]*t;
            else if(op=='/') d[i]=d[i]/t;
        }
        for(int j=1;j<=i;j++)
            d[0]=d[0]+d[j];
        printf("%.0f",d[0]);
    }
}