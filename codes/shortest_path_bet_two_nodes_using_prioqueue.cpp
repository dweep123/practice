#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
#define INF 10000000
struct sid {
	int a;
	int b;
};
int dis[1000001];
bool operator <(sid r , sid t){
	return r.b < t.b;
}

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n,m,s,t;
		scanf("%d %d %d %d",&n,&m,&s,&t);
		vector<sid> v[n+2];

		int i;
		for(i=0;i<=n;i++){
			dis[i]=INF;
		}
		int x,y,z;
		for(i=0;i<m;i++){
			scanf("%d %d %d",&x,&y,&z);
			v[x].push_back( (sid) { y,z});
			v[y].push_back( (sid)  { x,z});
		}
		priority_queue< sid > q;
		q.push( (sid) { s,0 });
		dis[s]=0;
		while ( !q.empty() ) {
			sid g=q.top();
			q.pop();
			for(i=0;i<v[g.a].size();i++){
				sid h=v[g.a][i];
				if(dis[g.a]+h.b < dis[h.a]){
					dis[h.a]=dis[g.a]+h.b;
					q.push(h);
				}
			}
		}
		if(dis[t]==INF){
			printf("NO PATH\n");
		}
		else{
			printf("%d\n",dis[t]);
		}
	}
	return 0;
}

