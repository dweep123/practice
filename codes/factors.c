#include<stdio.h>
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		long long int sum=0;
		int i;
		for(i=1;i<=n/2;i++){
			sum=sum+((n/i)-1)*i;
		}
		printf("%lld\n",sum);
	}
	return 0;
}

