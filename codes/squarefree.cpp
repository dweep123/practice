#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define max 10000007 
vector<bool>v(max,0);
int prime[max];
int main(){
	int i,j;
	int m;
	prime[1]=1;
	for(i=2;i<=max;i++){
		if(v[i]==0){
			prime[i]=i;
			j=2*i;
			while(j<=max){
				if(v[j]==0){
					v[j]=1;
					prime[j]=i;
				}
				j+=i;
			}
		}
	}
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		map<int,int>y;
		int maxx=0;
		map<int,int>::iterator it;
		while(1){
			if(prime[n]==1){
				break;
			}
			it=y.find(prime[n]);
			if(it==y.end()){
				y[prime[n]]=1;
				if(1 > maxx){
					maxx=1;
				}
			}
			else{
				it->second++;
				if(it->second > maxx){
					maxx=it->second;
				}
			}
			n=n/prime[n];
		}
		printf("%d\n",maxx);
	}
	return 0;
}


