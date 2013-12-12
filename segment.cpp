#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
vector<long long int >v;
void precompute(void){
	int i;
	v.push_back(1);
	v.push_back(1);
	long long int k;
	for(i=2;i<=3*1000000;i++){
		k=(v[i-1]*i)%3046201;
		v.push_back(k);
	}
}
int f[524288]; // n node me jo bhi range hai us range k sabhi elments me kya jodna hai(saare elemnts me)
int let[4];
int a[100010];
void init(int n,int s,int e){
	if(s==e){
		f[n]=a[s];
		return;
	}
	init(2*n,s,(s+e)/2);
	init(2*n+1,(s+e)/2+1,e);
	f[n]=f[2*n]+f[2*n+1];
	return;
}
void update(int n,int s,int e,int i,int j,int val){
	if(s==i && e==j){
		f[n]=val;
		a[s]=val;
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
}
int query(int n,int s,int e,int i,int j){
	if(s==i && e==j){
		return f[n];
	}	
	int l=(s+e)/2;
	int p1=0,p2=0;
	if(j<=l){
		p1=query(2*n,s,l,i,j);
	}
	else if(i>l){
		p2=query(2*n+1,l+1,e,i,j);
	}
	else{
		p1=query(2*n,s,l,i,l);
		p2=query(2*n+1,l+1,e,l+1,j);
	}
	return (p1+p2);
}
/*int power(int num,int po){
  if(po==0){
  return 1;
  }
  if(po==1){
  return num%3046201;
  }
  int y=power(num,po/2);
  if(po%2==0){
  return (y*y)%3046201;
  }
  else{
  return (y*y*num)%3046201;
  }
  }*/

int MAX=3046201;

int power(int a,int d)
{
	long long int x=1,y=a;
	while(d)
	{
		if(d%2==1)
			x=(x*y)%MAX;
		y=(y*y)%MAX;
		d/=2;
	}
	return x;
}

int inv(int a)
{
	int b=MAX-2;
	long long int x=1,y=a;
	while(b)
	{
		if(b%2==1)
			x=(x*y)%MAX;
		y=(y*y)%MAX;
		b/=2;
	}
	return x;
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
	precompute();
	int n,q;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	init(1,0,n-1);
	int x,y,z;
	int j=0;
	scanf("%d",&q);
	char s[100];
	int y1;
	long long int ans;
	for(i=0;i<q;i++){
		scanf("%s",s);
		if(strcmp(s,"change")==0){
			scanf("%d %d",&y,&z);
			update(1,0,n-1,y-1,y-1,z);
		}
		else{
			scanf("%d %d",&y,&z);

			y1=query(1,0,n-1,y-1,z-1);
			int k=z-y+1;
			int x=y1%k;
			long long int a=y1/k+1;
			long long int b=y1/k;
			a=power(v[a],x);
			b=power(v[b],k-x);
			a=(a*b)%3046201;
			a=(a*v[x])%3046201;
			a=(a*v[k-x])%3046201;
			b=(extendedEuclid(a,3046201).second.first + 3046201) % 3046201;
			ans=(((v[y1]*v[k])%3046201)*b)%3046201;
			printf("%lld\n",ans);

		}
	}
	return 0;
}
