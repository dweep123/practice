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
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,m;
		scanf("%d %d",&m,&n);
		int a[n+m],b[n+m],c[n+m],d[n+m];
		int i;
		int j=0;
		for(i=1;i<m;i++){
			scanf("%d",&a[j]);
			c[j]=1;
			j++;
		}
		for(i=1;i<n;i++){
			scanf("%d",&a[j]);
			c[j]=0;
			j++;
		}
		for(i=0;i<m+n;i++){
			b[i]=0;
			d[i]=0;
		}
		mergesort(a,0,j-1,b,c,d);
		/*	for(i=0;i<j;i++){
			printf("%d %d\n",a[i],c[i]);
			}
			printf("\n");*/
		int v=0;
		int h=0;
		long long int cost=0;
		for(i=j-1;i>=0;i--){
			if(c[i]==1){
				cost+=a[i]*(h+1);
				v++;
			}
			else if(c[i]==0){
				cost+=a[i]*(v+1);
				h++;
			}
		}
		printf("%lld\n",cost);
	}
	return 0;
}

