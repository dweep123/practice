#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double b[50001];
double h[50001];
double w[50001];
double d[50001];
const double INF = 2000000000, EPS = 1e-9;
const int MAX = 50005, LVL = 32;
double vol(double low,double high,int n){
	int i;
	double toret=0.0;
	double h1,h2;
	for(i=0;i<n;i++){
		h1=max(low,b[i]);
		h2=min(h[i],high);
		if(h2 > h1+EPS){
			toret=toret+w[i]*d[i]*(h2-h1);
		}
	}
	return toret;
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		int i;
		double hi=-INF;
		double lo=INF;
		for(i=0;i<n;i++){
			scanf("%lf %lf %lf %lf",&b[i],&h[i],&w[i],&d[i]);
			h[i]=h[i]+b[i];
			if(h[i] > hi){
				hi=h[i];
			}
			if(b[i] < lo){
				lo=b[i];
			}

		}
		double v;
		scanf("%lf",&v);
		if(vol(lo,hi,n)+EPS < v){
			printf("OVERFLOW\n");
		}
		else{
			double  mid;
			int cnt = LVL;
			double lowb=lo; // maximum times jitna ye chale is 32 times
			while(lo<=hi){
				mid=lo+(hi-lo)/2.0;
				if(vol(lowb,mid,n)+EPS == v){
					lo=mid;
					break;
				}
				if(vol(lowb,mid,n)+EPS < v){
					lo=mid;
				}
				else{
					hi=mid;
				}
				cnt--;
				if(cnt==0){
					break;
				}
			}

			printf("%.2lf\n",lo+EPS);
		}
	}
	return 0;
}


