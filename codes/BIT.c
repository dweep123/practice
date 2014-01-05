#include<stdio.h>
#include<math.h>
#define max 100001
long long int a[max];
long long int bit[max];
int root[max];
void add(int x,long long int val,int n){
	while(x <= n){
		bit[x] += val;
		x += (x & -x);
	}
}

long long int sum(int x){
	long long int ret=0;
	while(x>0){
		ret+=bit[x];
		x-=(x&-x);
	}
	return ret;
}

int find(int x){
	if(x!=root[x]){
		root[x]=find(root[x]);
	}
	return root[x];
}
void modify(int x,int y,int n){
	int i=find(x);
	while( x<=i && i<=y){
		if(a[i]!=1){
			add(i,-a[i],n);
			a[i]=sqrt(a[i]);
			add(i,a[i],n);
			if(a[i]==1){
				root[i]=i+1;
			}
		}
		i=find(i+1);
	}
}
int main(){
	int n,l;
	int i;
	for(l=1;scanf("%d",&n)==1;l++){
		for(i=1;i<=n;i++){
			bit[i]=0;
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			add(i,a[i],n);
			root[i]=i;
		}
		int m;
		scanf("%d",&m);
		int x,y,z;
		int temp;
		printf("Case #%d:\n",l);
		for(i=0;i<m;i++){
			scanf("%d %d %d",&x,&y,&z);
			if(y>z){
				temp=z;
				z=y;
				y=temp;
			}
			if(x==0){
				modify(y,z,n);
			}
			if(x==1){
				printf("%lld\n",sum(z)-sum(y-1));
			}
		}
		printf("\n");
	}return 0;
}

