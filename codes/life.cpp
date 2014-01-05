#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int grid[30][30];
bool dp[30][30][1300];
const int INF=10000000;
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		memset(dp,false,sizeof(dp));
		int n,m;
		int a,b;
		scanf("%d %d %d %d",&n,&m,&a,&b);
		int i,j;
		int k;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&grid[i][j]);
				if(i==0){
					dp[i][j][grid[i][j]+650]=true;
				}
			}
		}
		for(i=0;i<n-1;i++){
			for(j=0;j<m;j++){
				for(k=25;k<=1275;k++){
					if(dp[i][j][k]){
						if(j-1>=0){
							dp[i+1][j-1][k+grid[i+1][j-1]]=true;
						}
						dp[i+1][j][k+grid[i+1][j]]=true;
						if(j+1<m){
							dp[i+1][j+1][k+grid[i+1][j+1]]=true;

						}
					}
				}
			}
		}
		int min=INF;
		int max=-INF;
		for(i=0;i<m;i++){
			for(k=25;k<=1275;k++){
				if(dp[n-1][i][k]){
					if(k-650>= a && k-650 <=b){
						if(k-650 < min){
							min=k-650;
						}
						if(k-650 > max){
							max=k-650;
						}
					}
				}
			}
		}
		if(min!=INF){
			printf("%d ",min);
		}
		else{
			printf("NO ");
		}
		if(max!=-INF){
			printf("%d\n",max);
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}

