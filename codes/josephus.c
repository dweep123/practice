#include<stdio.h>
#include<string.h>
int main(){
	while(1){
		int n,d;
		scanf("%d %d",&n,&d);
		if(n==0&& d==0){
			break;
		}
		int safe=0;
		int i;
		for(i=2;i<=n;i++){
			safe=(safe+d)%i;
		}
		printf("%d %d %d\n",n,d,safe+1);
	}
	return 0;

}

