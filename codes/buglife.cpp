#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int> graph[2100];
int g[2100];
bool dfs(int i){
	bool r=true;
	int j;
	for(j=0;j<graph[i].size();j++){
		if(g[i]==g[graph[i][j]]){
			return false;
		}
		if(g[graph[i][j]]==0){
			g[graph[i][j]]=-g[i];
			r=r and dfs(graph[i][j]);
		}
	}
	return r;
}

int main(){
	int tc;
	scanf("%d",&tc);
	int l=1;
	while(tc--){
		int n,m;
		scanf("%d %d",&n,&m);
		int i;
		for(i=1;i<=n;i++){
			graph[i].clear();
			g[i]=0;
		}
		int x,y;
		for(i=0;i<m;i++){
			scanf("%d %d",&x,&y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		bool r = true;
		for(i=1;i<=n;i++){
			if(g[i]==0){
				g[i]=1;
				r=r and dfs(i);
			}
		}
		if(r){
			printf("Scenario #%d:\n",l);
			printf("No suspicious bugs found!\n");
			l++;
		}
		else{
			printf("Scenario #%d:\n",l);
			printf("Suspicious bugs found!\n");
			l++;
		}
	}
	return 0;
}


