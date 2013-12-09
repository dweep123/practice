#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int nb=0,ns=0,nc=0;
int ab,as,ac;
int pb,ps,pc;
long long int r;
long long int ret(long long int n){
	long long int c=r;
	if((pb*(nb*n-ab))>=0){
	c=c-(pb*(nb*n-ab));
	}
	if((ps*(ns*n-as))>=0){
	c=c-(ps*(ns*n-as));
	}
	if((pc*(nc*n-ac))>=0){
	c=c-(pc*(nc*n-ac));
	}
	return c;
	if(c>=0){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	char s[1000];
	scanf("%s",s);
	int i;
	for(i=0;i<strlen(s);i++){
		if(s[i]=='B'){
			nb++;
		}
		else if(s[i]=='S'){
			ns++;
		}
		else if(s[i]=='C'){
			nc++;
		}
	}
	cin >> ab >> as >> ac;
	cin >> pb >> ps >> pc;
	cin >> r;
//	printf("%d %d %d %d %d %d %d %d %d %lld\n",nb,ns,nc,ab,as,ac,pb,ps,pc,r);
	long long int hi=10*r+ab+as+ac;
	long long int lo=0;
	long long int maxx=0;
	long long int mid;
	while(hi>=lo){
		mid=(lo+hi)/2;
	//	printf("%lld %lld\n",mid,ret(mid));
		if(ret(mid)>=0){
			if(mid >=maxx){
				maxx=mid;
			}
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	cout << maxx << endl;
	return 0;
}
