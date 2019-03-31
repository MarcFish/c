#include<stdio.h>
#include<string.h>
#define Max(a,b) a>b?a:b
struct FLOAT{
    int d[1000];
    int f[1000];
    int d_size;
    int f_size;
    void init(void){
        memset(d,0,sizeof(d));
        memset(f,0,sizeof(f));
        d_size=0;
        f_size=0;
    }
    void input(char s[]){
        init();
        int i;
        for(i=0;s[i]!='.';i++)
            d_size++;
        i++;
        for(;s[i]!='\0';i++)
            f_size++;
        for(int j=0,k=d_size-1;j<d_size;j++,k--)
            d[j]=s[k]-'0';
        for(int j=0,k=d_size+1;j<f_size;j++,k++)
            f[j]=s[k]-'0';
        return;
    }
    FLOAT operator + (const FLOAT &A) const{
        FLOAT ret;
        ret.init();
        int carry=0;ret.f_size=Max(A.f_size,f_size);
        for(int i=ret.f_size-1;i>=0;i--){
            int tmp=A.f[i]+f[i]+carry;
            carry=tmp/10;
            tmp=tmp%10;
            ret.f[i]=tmp;
        }
        for(int i=0;i<A.d_size||i<d_size;i++){
            int tmp=A.d[i]+d[i]+carry;
            carry=tmp/10;
            tmp=tmp%10;
            ret.d[ret.d_size++]=tmp;
        }
        if(carry!=0){
            ret.d[ret.d_size++];
        }
        return ret;
    }
    void output(void){
        for(int i=d_size-1;i>=0;i--)
            printf("%d",d[i]);
        printf(".");
        for(int i=0;i<f_size;i++)
            printf("%d",f[i]);
        return;
    }
}a,b,c;
int main(void){
    char x[1000],y[1000];
    while(scanf("%s",x)!=EOF){
        scanf("%s",y);
        a.input(x);b.input(y);
        c=a+b;
        c.output();
    }
    return 0;
}