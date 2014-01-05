#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
#define max 100000000 
vector<bool>v(max/2+100,0);
int a[5761456];
int main(){
	int i,j;
	int m;
	for(i=3;i<10000;i+=2){
		if(v[(i-3)/2]==0){
			j=i*i;
			m=2*i;
			while(j<max){
				v[(j-3)/2]=1;
				j+=m;
			}
		}
	}
	j=1;
	a[1]=2;
	j=2;
	for(i=3;i<max;i+=2){
		if(v[(i-3)/2]==0){
			a[j]=i;
			j++;
		}
	}
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0){
			break;
		}
		int lo=1;
		int hi=j-1;
		int mid;
		int ans=0;
		while(lo<=hi){
			mid=lo+(hi-lo)/2;
			if(a[mid] > n){
				hi=mid-1;
			}
			else if(a[mid]<n){
				lo=mid+1;
				ans=mid;
			}
			else if(a[mid]==n){
				ans=mid;
				break;
			}
		}
		double r,x;
		x = n;
		r = ( fabs(ans - x/log(x)) / ans ) * 100.0;
		printf("%.1lf\n", r);
	}
	return 0;
}

