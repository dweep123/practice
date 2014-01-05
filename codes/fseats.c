#include<stdio.h>
const int INF=10000000;
int main(){
	while(1){
		int r,c,k;
		scanf("%d %d %d",&r,&c,&k);
		if(r==0){
			break;
		}
		int dp[r+5][c+5];
		char s[500];
		int i,j;
		for(i=0;i<=r;i++){
			for(j=0;j<=c;j++){
				dp[i][j]=0;
			}
		}
		for(i=0;i<r;i++){
			scanf("%s",s);
			for(j=0;j<c;j++){
				if(j-1>=0){
					dp[i][j]+=dp[i][j-1];
				}
				if(i-1>=0){
					dp[i][j]+=dp[i-1][j];
				}
				if(i-1>=0 && j-1 >=0){
					dp[i][j]-=dp[i-1][j-1];
				}
				if(s[j]=='.'){
					dp[i][j]++;
				}

			}
		}
		int min=INF;
		int y;
		int st,e;
		for(i=0;i<r;i++){
			for(j=i;j<r;j++){
				st=0;
				e=0;
				if((j-i+1)*c<k) continue;
				//			if((j-i+1)*c>=k){
				while(1){
					y=dp[j][e];
					if(st-1>=0){
						y-=dp[j][st-1];
					}
					if(i-1>=0){
						y-=dp[i-1][e];
					}
					if(i-1>=0 && st-1 >=0){
						y+=dp[i-1][st-1];
					}
					if(y>=k){
						if((j-i+1)*(e-st+1)<=min){
							min=(j-i+1)*(e-st+1);
							//		printf("%d\n",min);
						}
						st++;
						if(st==c){
							break;
						}
						continue;
					}
					//	else{
					e++;
					if(e==c){
						break;
					}
					//}
				}
				//}
			}
		}
		printf("%d\n",min);
	}
	return 0;
}



