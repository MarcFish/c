#include<stdio.h>
//最大公约数
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int zuidagongyueshu(void){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        printf("%d\n",gcd(a,b));
    }
    return 0;
}
//最小公倍数
int zuixiaogongbeishu(void){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        printf("%d\n",a*b/gcd(a,b));
    }
    return 0;
}