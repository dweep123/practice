#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int v;
		int n;
		scanf("%d %d",&v,&n);
		int val[n+1];
		int c[n+1];
		int u[n+1];
		int i;
		vector<int> attch[n+1];
		int asli[n+1];
		int j=1;
		int x,y,z;
		for(i=1;i<=n;i++){
			scanf("%d %d %d",&x,&y,&z);
			if(z==0){
				val[j]=x;
				c[j]=y;
				u[j]=z;
				asli[j]=i;
				j++;
			}
			else{
				attch[z].push_back(x);
				attch[z].push_back(y);
			}
		}
		y=j-1;
		int dp[y+1][v+1];
		for(i=0;i<=v;i++){
			dp[0][i]=0;
		}
		for(i=0;i<=y;i++){
			dp[i][0]=0;
		}
		for(i=1;i<=y;i++){
			for(j=1;j<=v;j++){
				dp[i][j]=dp[i-1][j];
				if(j>=val[i]){
					if(dp[i-1][j-val[i]]+c[i]*val[i] > dp[i][j]){
						dp[i][j]=dp[i-1][j-val[i]]+c[i]*val[i];
					}
					if(attch[asli[i]].size()>=2){
						if(j >= val[i]+attch[asli[i]][0]){
							if(dp[i-1][j-(val[i]+attch[asli[i]][0])]+c[i]*val[i]+attch[asli[i]][0]*attch[asli[i]][1] > dp[i][j]){
								dp[i][j]= dp[i-1][j-(val[i]+attch[asli[i]][0])]+c[i]*val[i]+attch[asli[i]][0]*attch[asli[i]][1];
							}
						}
					}
					if(attch[asli[i]].size()>=4){
						if(j >= val[i]+attch[asli[i]][0]+attch[asli[i]][2]){
							if(dp[i-1][j-(val[i]+attch[asli[i]][0]+attch[asli[i]][2])]+c[i]*val[i]+attch[asli[i]][0]*attch[asli[i]][1]+attch[asli[i]][2]*attch[asli[i]][3] > dp[i][j]){
								dp[i][j]= dp[i-1][j-(val[i]+attch[asli[i]][0]+attch[asli[i]][2])]+c[i]*val[i]+attch[asli[i]][0]*attch[asli[i]][1]+attch[asli[i]][2]*attch[asli[i]][3];
							}
						}
					}
				}
			}
		}
		printf("%d\n",dp[y][v]);
	}
	return 0;
}


