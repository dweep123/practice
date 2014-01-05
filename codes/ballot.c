#include<stdio.h>
int main(){
	while(1){
		int n,b;
		scanf("%d %d",&n,&b);
		if(n==-1 && b==-1){
			break;
		}
		int a[n];
		int i;
		int ma=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i] > ma){
				ma=a[i];
			}
		}
		int lo=0;
		int hi=ma;
		int mid;
		int count=0;
		int min=ma+1;
		while(lo <= hi){
			mid=lo+(hi-lo)/2;
			count=0;
			for(i=0;i<n;i++){
				if(a[i] >= mid){
					count=count+a[i]/mid;
					if(a[i]%mid!=0){
						count++;
					}
				}
				else{
					count++;
				}
			}
			if(count <= b){
				if(mid < min){
					min=mid;
				}
				hi=mid-1;
			}
			else{
				lo=mid+1;
			}
		}
		printf("%d\n",min);
	}
	return 0;
}


