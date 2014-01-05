#include<stdio.h>
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc>0){
		int n,i,j;
		scanf("%d",&n);
		int s[n];
		int e[n];
		for(i=0;i<n;i++){
			scanf("%d",&s[i]);
			scanf("%d",&e[i]);
		}
		int min,temp;
		for(i=0;i<n;i++){
			min=i;
			for(j=i+1;j<n;j++){
				if(e[j] < e[min]){
					min=j;
				}
			}
			temp=e[min];
			e[min]=e[i];
			e[i]=temp;
			temp=s[min];
			s[min]=s[i];
			s[i]=temp;
		}
		int a[n];
		for(i=0;i<n;i++){
			a[i]=0;
		}
		int count=1;
		int k=0;
		for(i=1;i<n;i++){
			if(a[i]==0){
				if(s[i] >= e[k]){
					a[i]=1;
					count++;
					k=i;
				}
			}
		}
		printf("%d\n",count);
		tc--;
	}
	return 0;
}

