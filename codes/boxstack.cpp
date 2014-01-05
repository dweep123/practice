#include<cstdio>
#include<algorithm>
using namespace std;
void  merge(int a[],int be,int m, int n,int b[],int c[],int d[],int e[],int f[]){
	int i=be,j=m+be,k=0;
	while(1){
		if(i==m+be || j==n+1){
			break;
		}
		if(a[i]*c[i]<=a[j]*c[j]){
			b[k]=a[i];
			d[k]=c[i];
			f[k]=e[i];
			k++;
			i++;

		}
		else{
			b[k]=a[j];
			d[k]=c[j];
			f[k]=e[j];
			k++;
			j++;
		}
	}
	while(i<m+be){
		b[k]=a[i];
		d[k]=c[i];
		f[k]=e[i];
		k++;
		i++;
	}
	while(j<n+1){
		b[k]=a[j];
		d[k]=c[j];
		f[k]=e[j];
		k++;
		j++;
	}
	return;
}
void mergesort( int a[],int begin, int  end,int b[],int c[],int d[],int e[],int f[]){
	if(begin>=end){
		return;
	}

	int  mid=(end+1-begin)/2;
	int i,k=0;
	mergesort(a,begin,mid -1+begin,b,c,d,e,f);
	mergesort(a,mid+begin,end,b,c,d,e,f);
	merge(a,begin,mid,end,b,c,d,e,f);
	for(i=begin;i<=end;i++){
		a[i]=b[k];
		c[i]=d[k];
		e[i]=f[k];
		k++;
	}
	return;
}
int h[100];
int w[100];
int d[100];
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0){
			break;
		}
		int i,k;
		k=0;

		int he,we,de;
		for(i=0;i<n;i++){
			scanf("%d %d %d",&he,&we,&de);
			h[k]=he;
			w[k]=min(we,de);
			d[k]=max(we,de);
			k++;
			h[k]=w[k-1];
			w[k]=min(h[k-1],d[k-1]);
			d[k]=max(h[k-1],d[k-1]);
			k++;
			h[k]=d[k-2];
			w[k]=min(h[k-2],w[k-2]);
			d[k]=max(h[k-2],w[k-2]);
			k++;
		}
		int b[k];
		int e[k];
		int f[k];
		for(i=0;i<k;i++){
			b[i]=0;
			e[i]=0;
			f[i]=0;
		}
		//		printf("\n");
		mergesort(d,0,k-1,b,w,e,h,f);
		/*for(i=0;i<k;i++){
		  printf("%d %d %d\n",h[i],w[i],d[i]);
		  }*/
		int dp[k];
		dp[0]=h[0];
		int j;
		int max=dp[0];
		int ind=0;
		for(i=1;i<k;i++){
			dp[i]=h[i];
			for(j=0;j<i;j++){
				if(w[j]<w[i] && d[j]<d[i]){
					if(dp[j]+h[i] > dp[i]){
						dp[i]=dp[j]+h[i];
					}
				}
			}
			if(dp[i]> max){
				max=dp[i];
				ind=i;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}

