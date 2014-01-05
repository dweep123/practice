#include<stdio.h>
#include<math.h>

int  n,q;
int a[100000];


int prime[ 2000001 ]={0};
int set[524288];
int f[524288];
void init(int n,int s,int e){
	set[n]=0;
	if(s==e){
		if(a[s]==2){
			f[n]=1;
		}
		else if(a[s]%2==1 && prime[a[s]]==0){
			f[n]=1;
		}
		else{
			f[n]=0;
		}
		return;
	}
	init(2*n,s,(s+e)/2);
	init(2*n+1,(s+e)/2+1,e);
	f[n]=f[2*n]+f[2*n+1];
	return;
}
void update(int n,int s,int e,int i,int j, int val){
	if(s==i && e==j){
		set[n]=val;
		set[2*n]=0;
		set[2*n+1]=0;
		if(val==2){

			f[n]=(j-i+1);
		}
		else if(val%2==1 && prime[val]==0){
			f[n]=(j-i+1);
		}
		else{
			f[n]=0;
		}
		return ;
	}
	int l=(s+e)/2;
	if(set[n]!=0){
		set[2*n]=set[n];
		set[2*n+1]=set[n];
		if(set[n]==2){
			f[2*n]=(l-s+1);
			f[2*n+1]=(e-l);
		}
		else if(set[n]%2==1 && prime[set[n]]==0){
			f[2*n]=(l-s+1);
			f[2*n+1]=(e-l);

		}
		else{
			f[2*n]=0;
			f[2*n+1]=0;
		}
	}
	if(j<=l){
		update(2*n,s,l,i,j,val);
	}
	else if(i>l){
		update(2*n+1,l+1,e,i,j,val);
	}
	else{
		update(2*n,s,l,i,l,val);
		update(2*n+1,l+1,e,l+1,j,val);

	}
	f[n]=f[2*n]+f[2*n+1];
	set[n]=0;
	return ;
}
int query(int n,int s,int e,int i,int j,int v){
	if(s==i && e==j){
		if(v!=0){
			if(v==2){

				return (j-i+1);
			}
			if(v%2==1 && prime[v]==0){
				return (j-i+1);
			}
			else{
				return 0;
			}
		}
		return f[n];
	}
	int toset=v;
	if(v==0){
		toset=set[n];
	}
	int l=(s+e)/2;
	int p1=0,p2=0;
	if(j<=l){
		p1=query(2*n,s,l,i,j,toset);
	}
	else if(i>l){
		p2=query(2*n+1,l+1,e,i,j,toset);
	}
	else{
		p1=query(2*n,s,l,i,l,toset);
		p2=query(2*n+1,l+1,e,l+1,j,toset);
	}
	return (p1+p2);
}
int main(){


	int i;
	int j=0;
	for(i=3;i<=1000;i++){
		if(prime[i]==0){
			j=i*i;
			while(j<=1000000){
				prime[j]=1;
				j+=i;
			}
		}
	}




	/*	for ( i = 0; i <= 1000000; ++i ) {
		prime[ i ] = 1;
		}
		for ( i = 2; i <= 1000000; ++i ) {
		for ( j = i * 2; j <= 1000000; j += i ) {
		prime[ j ] = 0;
		}
		}*/
	int tc;
	scanf("%d",&tc);
	int l=1;
	while(tc--){
		scanf("%d %d",&n,&q);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		init(1,0,n-1);
		int x,y,z;
		int val;
		printf("Case %d:\n",l);
		l++;
		for(i=0;i<q;i++){
			scanf("%d %d %d",&x,&y,&z);
			if(x==0){
				scanf("%d",&val);
				update(1,0,n-1,y-1,z-1,val);
			}
			else if(x==1){
				printf("%d\n", query(1,0,n-1,y-1,z-1,0));
			}
		}
	}
	return 0;
}

