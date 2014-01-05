#include<stdio.h>
#include<string.h>
long long int dp[1000000];
long long int su[1000000];
char s[1000000];
int l[256];
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		scanf("%s",s);
		int i;
		int n=strlen(s);
		for(i=0;i<256;i++){
			l[i]=-1;
		}
		for(i=0;i<n;i++){
			dp[i]=0;
			su[i]=0;
		}
		dp[0]=1;
		su[0]=2;
		l[s[0]]=0;
		for(i=1;i<n;i++){
			if(l[s[i]]==-1){
				dp[i]=su[i-1];
				if(dp[i] <0){
					dp[i]=dp[i]+1000000007;
				}
				if(dp[i] >= 1000000007){
					dp[i]=dp[i]-1000000007;
				}
			}
			else if(l[s[i]]==0){
				dp[i]=su[i-1]-1;
				if(dp[i] <0){
					dp[i]=dp[i]+1000000007;
				}
				if(dp[i] >= 1000000007){
					dp[i]=dp[i]-1000000007;
				}
			}
			else{
				dp[i]=su[i-1]-su[l[s[i]]-1];
				if(dp[i] <0){
					dp[i]=dp[i]+1000000007;
				}
				if(dp[i] >= 1000000007){
					dp[i]=dp[i]-1000000007;
				}
			}
			su[i]=su[i-1]+dp[i];
			if(su[i]<0){
				su[i]=su[i]+1000000007;
			}
			if(su[i] >= 1000000007){
				su[i]=su[i]-1000000007;
			}
			l[s[i]]=i;
		}
		printf("%llu\n",su[n-1]);
	}
	return 0;
}


