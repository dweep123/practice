#include<iostream>
#include<vector>
#include<cstdio>
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
	int n;
	vector<int>y;
	while(scanf("%d",&n)!=EOF){
		printf("1");
		y.clear();
		while(1){
			if(prime[n]==1){
				break;
			}
			y.push_back(prime[n]);
			//			printf(" x %d",prime[n]);
			n=n/prime[n];
		}
		for(i=0;i<y.size();i++){
			printf(" x %d",y[i]);
		}
		printf("\n");
	}
	return 0;
}

