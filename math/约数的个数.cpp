
#include<stdio.h>
int count(int n){
	int i;
	int count=0;
	if(n==1)
	return 1;
	else{
	for(i=1;i*i<=n;i++){
		if(n%i==0&&i*i!=n)
		count=count+2;
		if(n%i==0&&i*i==n)
		count++;	
	}
	return count;
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
	int a[n];
	int j;
	for(j=0;j<n;j++){
		scanf("%d",&a[j]); 
	} 
	for(j=0;j<n;j++){
		printf("%d\n",count(a[j]));
	}
	
}
}
