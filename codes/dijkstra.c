#include<stdio.h>
int g[110][110];
int known[110][110];
long long int dis[110][110];
const long long int INF=1000000000;
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		int m;
		scanf("%d",&m);
		scanf("%d",&n);
		int i;
		int x,y;
		long long int z;
		for(i=1;i<=m;i++){
			for(x=1;x<=n;x++){
				scanf("%d",&g[i][x]);
				known[i][x]=0;
				dis[i][x]=INF;
			}
		}
		scanf("%d %d %lld",&x,&y,&z);

		int count=0;
		dis[1][1]=g[1][1];
		int mini=1;
		int minj=1;
		long long int dmin;
		int j;
		while(count<n*m){
			if(mini==x && minj==y){
				break;
			}
			known[mini][minj]=1;
			count++;
			if(mini-1>=1){
				if(dis[mini][minj]+g[mini-1][minj] <= dis[mini-1][minj]){
					dis[mini-1][minj]=dis[mini][minj]+g[mini-1][minj];
				}
			}

			if(mini+1 <=m){
				if(dis[mini][minj]+g[mini+1][minj] <= dis[mini+1][minj]){
					dis[mini+1][minj]=dis[mini][minj]+g[mini+1][minj];
				}
			}
			if(minj-1>=1){
				if(dis[mini][minj]+g[mini][minj-1] <= dis[mini][minj-1]){
					dis[mini][minj-1]=dis[mini][minj]+g[mini][minj-1];
				}
			}

			if(minj+1<=n){
				if(dis[mini][minj]+g[mini][minj+1] <= dis[mini][minj+1]){
					dis[mini][minj+1]=dis[mini][minj]+g[mini][minj+1];
				}
			}
			mini=0;
			minj=0;
			dmin=INF;
			for(i=1;i<=m;i++){
				for(j=1;j<=n;j++){
					if(known[i][j]==0 && dis[i][j] <= dmin){
						mini=i;
						minj=j;
						dmin=dis[i][j];
					}
				}
			}
		}
		if(dis[x][y]<=z){
			printf("YES\n");
			printf("%lld\n",z-dis[x][y]);
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}


