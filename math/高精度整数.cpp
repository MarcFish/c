#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
#define sys 10
#define maxDigits 10000
struct bigInteger{
    int digit[maxDigits];//表示一位，从低到高，
    int size;//下一位
    void init(){
        memset(digit,0,sizeof(digit));
        size=0;
        return;
    }
    void set(int x){
        init();
        do{
            digit[size++]=x%sys;
            x/=sys;
        }while(x);
        return;
    }
    void input(string s){
        for(int i=s.length();i>=0;i--){
            digit[i]=s[i]-'0';
            size++;
        }
        return;
    }
    void output(){
        for(int i=size-1;i>=0;i--){
            if(i!=size-1) printf("%d",digit[i]);//根据sys进行改变
            else printf("%d",digit[i]);
        }
        printf("%\n");
        return;
    }
    bigInteger operator * (const int x) const{
        bigInteger ret;
        ret.init();
        int carry=0;
        for(int i=0;i<size;i++){
            int tmp=x*digit[i]+carry;
            carry=tmp/sys;
            ret.digit[ret.size++]=tmp%sys;
        }
        if(carry!=0){
            ret.digit[ret.size++]=carry;
        }
        return ret;
    }
    bigInteger operator + (const bigInteger&A) const{
        bigInteger ret;
        ret.init();
        int carry=0;
        for(int i=0;i<size||i<A.size;i++){
            int tmp=A.digit[i]+digit[i]+carry;
            carry=tmp/sys;
            ret.digit[ret.size++]=tmp%sys;
        }
        if(carry!=0){
            ret.digit[ret.size++]=carry;
        }
        return ret;
    }
    bigInteger operator / (const int x) const{
        bigInteger ret;
        ret.init();
        int remainder=0;
        for(int i=size-1;i>=0;i--){
            int tmp=digit[i]+remainder*sys;
            remainder=tmp%x;
            ret.digit[i]=tmp/x;
        }
        ret.size=0;
        for(int i=0;i<maxDigits;i++)
            if(ret.digit[i]!=0) ret.size=i;
        ret.size++;
        return ret;
    }
    int operator %(const int x) const{
        int remainder=0;
        for(int i=size-1;i>=0;i--){
            remainder=(digit[i]+remainder*sys)%x;
        }
        return remainder;
    }
    bool operator == (const bigInteger &A)const{
        if(size!=A.size) return false;
        else{
            for(int i=0;i<size;i++){
                if(digit[i]!=A.digit[i]) return false;
            }
            return true;
        }
    }
};
