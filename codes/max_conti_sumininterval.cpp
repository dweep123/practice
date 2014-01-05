#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct gss{
	int sum,suff,pre,best;
};
gss f[524288];
int a[100010];

void init(int n,int s,int e){
	if(s==e){
		f[n].sum=a[s];
		f[n].suff=a[s];
		f[n].pre=a[s];
		f[n].best=a[s];
		return;
	}
	init(2*n,s,(s+e)/2);
	init(2*n+1,(s+e)/2+1,e);
	f[n].sum=f[2*n].sum+f[2*n+1].sum;

	f[n].suff=max(f[2*n+1].suff,(f[2*n+1].sum+f[2*n].suff));

	f[n].pre=max(f[2*n].pre,(f[2*n].sum+f[2*n+1].pre));

	f[n].best=max(max(f[2*n].best,f[2*n+1].best),(f[2*n].suff+f[2*n+1].pre));
	return;
}
/*void update(int n,int s,int e,int i,int j,int val){
  if(s==i && e==j){
  f[n]=val;
  return ;
  }
  int l=(s+e)/2;
  if(j<=l)
  update(2*n,s,l,i,j,val);
  else if(i>l)
  update(2*n+1,l+1,e,i,j,val);
  else{
  update(2*n,s,l,i,l,val);
  update(2*n+1,l+1,e,l+1,j,val);

  }
  f[n]=f[2*n]+f[2*n+1];
  return ;
  }*/
gss query(int n,int s,int e,int i,int j){
	if(s==i && e==j){
		return f[n];
	}	
	int l=(s+e)/2;
	gss p1,p2;
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
		gss b;
		b.sum=p1.sum+p2.sum;

		b.suff=max(p2.suff,(p2.sum+p1.suff));

		b.pre=max(p1.pre,(p1.sum+p2.pre));

		b.best=max(max(p1.best,p2.best),(p1.suff+p2.pre));
		return b;

	}
}
long long int power(long long int num,int po){
	if(po==0){
		return 1;
	}
	if(po==1){
		return num;
	}
	long long int y=power(num,po/2);
	if(po%2==0){
		return y*y;
	}
	else{
		return y*y*num;
	}
}
pair<int, pair<int, int> > extendedEuclid(long long int a, int b) {
	int x = 1, y = 0;
	int xLast = 0, yLast = 1;
	int q, r, m, n;
	while(a != 0) {
		q = b / a;
		r = b % a;
		m = xLast - q * x;
		n = yLast - q * y;
		xLast = x, yLast = y;
		x = m, y = n;
		b = a, a = r;
	}
	return make_pair(b, make_pair(xLast, yLast));
}

int main(){
	int n,q;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	init(1,0,n-1);
	int x,y;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d %d",&x,&y);
		gss d=query(1,0,n-1,x-1,y-1);
		printf("%d\n",d.best);
	}

	return 0;
}

