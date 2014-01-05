#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#define max 100010
using namespace std;
string s;
int rank[20][max];
int n;
struct abc{
	int fh;
	int sh;
	int ind;
};
abc a[max];
bool compare(abc x,abc y){
	if(x.fh==y.fh){
		return x.sh < y.sh;
	}
	return x.fh < y.fh;
}
int tr=1;
void make_suffix_array(){
	int i;
	for(i=0;i<n;i++){
		rank[0][i]=s[i];
	}
	int count=1;
	while(count < n){
		for(i=0;i<n;i++){
			a[i].ind=i;
			a[i].fh=rank[tr-1][i];
			if(i+count < n){
				a[i].sh=rank[tr-1][i+count];
			}
			else{
				a[i].sh=-1;
			}
		}
		sort(a,a+n,compare);
		rank[tr][a[0].ind]=0;
		int yr=0;
		for(i=1;i<n;i++){
			if(a[i].fh!=a[i-1].fh || a[i].sh!=a[i-1].sh){
				yr++;
			}
			rank[tr][a[i].ind]=yr;
		}
		tr++;
		count=count*2;
	}
}
long long int lcp(int x,int y){
	int i;
	long long int ret=0;
	for(i=tr-1;i>=0;i--){
		if(x>=n || y>=n){
			break;
		}
		if(rank[i][x]==rank[i][y]){
			ret+=1<<i;
			x+=1<<i;
			y+=1<<i;
		}
	}
	return ret;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		cin >> s;
		tr=1;
		n=s.length();
		make_suffix_array();
		int i;
		/*for(i=0;i<n;i++){
			printf("%d ",rank[tr-1][i]);
		}*/
		long long int ans=n*(n+1)/2;
		for(i=1;i<n;i++){
		ans=ans-lcp(a[i].ind,a[i-1].ind);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

