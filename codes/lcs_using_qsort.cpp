#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define max 50005
char s[max];
long long int n;
int val[max];
int comp(const void *a,const void *b){
	return(strcmp((s+*((int*)a)),(s+*((int*)b))));
}
void suffix_array(){
	int i;
	for(i=0;i<n;i++){
		val[i]=i;
	}
	qsort(val,n,sizeof(int),comp);
}
long long int lcp(){
	int i;
	char *x=s;
	char *y=s;
	long long int ret=0;
	for(i=1;i<n;i++){
		x=s+val[i];
		y=s+val[i-1];
		while(*x==*y){
			ret++;
			x++;
			y++;
		}
	}
	return ret;
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%s",s);
		n=strlen(s);
		suffix_array();
		long long int c=lcp();
		long long int y=(n*(n+1)/2)-c;
		printf("%lld\n",y);
	}
	return 0;
}
