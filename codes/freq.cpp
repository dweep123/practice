#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct gss{
	int suff,pre,count;
};
gss f[524288];
int a[100010];

void init(int n,int s,int e){
	if(s==e){
		f[n].suff=1;
		f[n].pre=1;
		f[n].count=1;
		return;
	}
	int l=(s+e)/2;
	init(2*n,s,l);
	init(2*n+1,l+1,e);
	int k;
	if(a[l]==a[l+1]){
		k=f[2*n].suff+f[2*n+1].pre;
		f[n].pre=f[2*n].pre;
		if(a[s]==a[l]){
			f[n].pre+=f[2*n+1].pre;
		}
		f[n].suff=f[2*n+1].suff;
		if(a[e]==a[l+1]){
			f[n].suff+=f[2*n].suff;
		}
		f[n].count=max(max(f[2*n].count,f[2*n+1].count),k);
	}
	else{
		f[n].pre=f[2*n].pre;
		f[n].suff=f[2*n+1].suff;
		f[n].count=max(f[2*n].count,f[2*n+1].count);
	}
	return ;
}
int query(int n,int s,int e,int i,int j){
	if(s==i && e==j){
		return f[n].count;
	}	
	int l=(s+e)/2;
	int p1,p2;
	int k;
	if(j<=l){
		p1=query(2*n,s,l,i,j);
		return p1;
	}
	else if(i>l){
		p2=query(2*n+1,l+1,e,i,j);
		return p2;
	}
	else{
		p1=query(2*n,s,l,i,l);
		p2=query(2*n+1,l+1,e,l+1,j);
		if(a[l]==a[l+1]){
			int k=min(f[2*n].suff,l-i+1)+min(f[2*n+1].pre,j-l);
			return max(max(p1,p2),k);
		}
		else{
			return max(p1,p2);
		}
	}
}
int main(){
	while(1){
		int n,q;
		scanf("%d",&n);
		if(n==0){
			break;
		}
		scanf("%d",&q);
		int i;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		init(1,0,n-1);
		int x,y;
		int d;
		for(i=0;i<q;i++){
			scanf("%d %d",&x,&y);
			d=query(1,0,n-1,x-1,y-1);
			printf("%d\n",d);
		}
	}

	return 0;
}

