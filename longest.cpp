#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int len[n+1];
	int l=1;
	len[1]=a[0];
	int lo,hi;
	int mid;
	int ans;
	for(i=1;i<n;i++){
		if(a[i] > len[l]){
			l++;
			len[l]=a[i];
		}
		else if(a[i] < len[1]){
			len[1]=a[i];
		}
		else{
			lo=1;
			hi=l;
			ans=l;
			while(lo<=hi){
				mid=(lo+hi)/2;
				if(len[mid] < a[i]){
					lo=mid+1;
				}
				else if(len[mid] > a[i]){
					if(mid < ans){
						ans=mid;
					}
					hi=mid-1;
				}
				else if(len[mid]==a[i]){
					ans=mid;
					break;
				}
			}
			len[ans]=a[i];
		}
	}
	printf("%d\n",l);
	return 0;
}
