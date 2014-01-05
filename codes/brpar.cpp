#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
vector<long long int >v;
long long int mod=1000000007;
void precompute(void){
	int i;
	v.push_back(1);
	v.push_back(1);
	long long int k;
	for(i=2;i<=2100;i++){
		k=(v[i-1]*i)%mod;
		v.push_back(k);
	}
}
int inv(int a)
{
	int b=mod-2;
	long long int x=1,y=a;
	while(b)
	{
		if(b%2==1)
			x=(x*y)%mod;
		y=(y*y)%mod;
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
int a[1000];
int main(){
	precompute();
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		int i;
		int su=0;
		long long int k=1;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			k=(k*v[a[i]])%mod;
			su+=a[i];
		}
		k=(k*v[su+1])%mod;
		long long int y=v[2*su]%mod;
		long long b=(extendedEuclid(k,mod).second.first + mod) % mod;
		long long int  ans=((y%mod)*b)%mod;
		printf("%lld\n",ans);

	}
	return 0;
}

