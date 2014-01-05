#include<stdio.h>
double g[110][110];
int known[110];
double dis[110];
const double INF=1000000000.0;
int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0){
			break;
		}
		int m;
		scanf("%d",&m);
		int i;
		int x,y;
		double z;
		for(i=0;i<=n;i++){
			known[i]=0;
			dis[i]=0.0;
			for(x=0;x<=n;x++){
				g[i][x]=-1;
			}
		}

		for(i=0;i<m;i++){
			scanf("%d %d %lf",&x,&y,&z);
			g[x][y]=z/100.0;
			g[y][x]=z/100.0;
		}
		int count=0;
		dis[1]=1.0;
		int min=1;
		double dmin;
		while(count<n){
			known[min]=1;
			if(min==n){
				break;
			}
			count++;
			for(i=1;i<=n;i++){
				if(known[i]==0 && g[min][i]!=-1){
					if(dis[min]*g[min][i] >= dis[i]){
						dis[i]=dis[min]*g[min][i];
					}
				}
			}
			min=0;
			dmin=0.0;
			for(i=1;i<=n;i++){
				if(known[i]==0 && dis[i] >= dmin){
					min=i;
					dmin=dis[i];
				}
			}
		}
		printf("%lf percent\n",dis[n]*100.0+1e-10);
	}
	return 0;
}


