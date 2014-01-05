#include<stdio.h>
const int MODULO = 1e8;
void  merge(int a[],int be,int m, int n,int b[],int c[],int d[]){
	int i=be,j=m+be,k=0;
	while(1){
		if(i==m+be || j==n+1){
			break;
		}
		if(a[i]<=a[j]){
			b[k]=a[i];
			d[k]=c[i];
			k++;
			i++;

		}
		else{
			b[k]=a[j];
			d[k]=c[j];
			k++;
			j++;
		}
	}
	while(i<m+be){
		b[k]=a[i];
		d[k]=c[i];
		k++;
		i++;
	}
	while(j<n+1){
		b[k]=a[j];
		d[k]=c[j];
		k++;
		j++;
	}
	return;
}
void mergesort( int a[],int begin, int  end,int b[],int c[],int d[]){
	if(begin>=end){
		return;
	}

	int  mid=(end+1-begin)/2;
	int i,k=0;
	mergesort(a,begin,mid -1+begin,b,c,d);
	mergesort(a,mid+begin,end,b,c,d);
	merge(a,begin,mid,end,b,c,d);
	for(i=begin;i<=end;i++){
		a[i]=b[k];
		c[i]=d[k];
		k++;
	}
	return;
}
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(n==-1){
			break;
		}
		int a[n],b[n],c[n],d[n];
		int i;
		for(i=0;i<n;i++){
			scanf("%d %d",&c[i],&a[i]);
		}
		for(i=0;i<n;i++){
			b[i]=0;
			d[i]=0;
		}
		mergesort(a,0,n-1,b,c,d);
		int new[n];
		new[0]=-1;
		int dp[n];
		dp[0]=1;
		if(c[1] >= a[0]){
			new[1]=0;
		}
		else{
			new[1]=-1;
		}
		int hi;
		int lo;
		int mid;
		int y=-1;
		for(i=n-1;i>1;i--){
			hi=i-1;
			lo=0;
			y=-1;
			while(lo <= hi){
				mid=lo+(hi-lo)/2;
				if(c[i]>=a[mid]){
					if(mid > y){
						y=mid;
					}
					lo=mid+1;
				}
				else{
					hi=mid-1;
				}
			}
			new[i]=y;
		}
		for(i=1;i<n;i++){
			y=0;
			if(new[i]!=-1){
				y=dp[new[i]];
			}
			dp[i]=(y+dp[i-1]+1) % MODULO;;
		}
		printf("%08d\n",dp[n-1]);
	}
	return 0;
}

