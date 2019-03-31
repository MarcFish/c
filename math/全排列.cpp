#include<stdio.h>
#include<algorithm>
using namespace std;
char s[6];
int main(void){
    while(scanf("%s",s)!=EOF){
        int i=0;
        while(s[i++]!='\0');
        i--;
        sort(s,s+i);
        do{
            printf("%s\n",s);
        }while(next_permutation(s,s+i));
        printf("\n");
    }
}