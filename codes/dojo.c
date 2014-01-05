#include<stdio.h>
#include<string.h>
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,i;
		char m[5000],j[5000];
		scanf("%d %s %d %s",&n,m,&i,j);
		int k=m[strlen(m)-1]-48;
		int kj=j[strlen(j)-1]-48;
		if(n%2==1 && k%2==1){
			if((i+kj)%2==0){
				printf("Possible.\n");
			}
			else{
				printf("Impossible.\n");
			}
		}
		else{
			printf("Impossible.\n");
		}
	}
	return 0;
}

