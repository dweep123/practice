#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,c;
		scanf("%d %d",&n,&c);
		vector<long long int> a;
		int i;
		long long int ma=0;
		long long int y;
		for(i=0;i<n;i++){
			scanf("%lld",&y);
			a.push_back(y);
			if(y > ma){
				ma=y;
			}
		}
		sort(a.begin(),a.end());
		long long int lo=0;
		long long int  hi=ma;
		long long int mid;
		long long int max=0;
		int t;
		int last;
		int pos;
		while(lo <= hi){
			mid=lo+(hi-lo)/2;
			last=a[0];
			t=1;
			pos=1;
			while(1){
				if(t>=c){
					break;
				}
				if(pos>=n){
					break;
				}
				while(1){
					if(pos>=n){
						break;
					}
					if(a[pos]-last >= mid){
						last=a[pos];
						pos++;
						t++;
						break;
					}
					pos++;
				}
			}
			if(t<c){
				hi=mid-1;
			}
			if(t>=c){
				lo=mid+1;
				if(mid > max){
					max=mid;
				}
			}
		}
		printf("%lld\n",max);
	}
	return 0;
}

