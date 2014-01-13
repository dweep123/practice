	// A C++ program to find maximal Bipartite matching.
#include <iostream>
#include <string.h>
#include<cstdio>
using namespace std;
int n,m;
int bpGraph[120][120];
	int matchR[120];
bool bpm(int u, bool seen[], int matchR[])
{

	seen[u]=true;
	for (int v = 0; v < n; v++)
	{
		if (bpGraph[u][v] && !seen[v])
		{
			seen[u]=true;
			seen[v] = true; // Mark v as visited
		if (matchR[v] < 0 || bpm(matchR[v], seen, matchR))
			{
				matchR[v]=u;
				matchR[u]=v;
				return true;
			}
		}
	}
	return false;
}

int maxBPM()
{
	int result = 0; // Count of jobs assigned to applicants
	for (int u = 0; u < n; u++)
	{
		if(matchR[u] < 0){
		bool seen[n];
			//printf("u=%d\n",u);*/
			memset(seen,0, sizeof(seen));
			if (bpm(u, seen, matchR))
				result++;
		}
	}
	return result;
}
int main()
{
	int tc;
	cin >> tc;
	while(tc--){
	//	printf("tcbegibs\n");
		cin >> n >> m;
		int i,j;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				bpGraph[i][j]=0;
			}
		}
		int x,y;
		for(i=0;i<m;i++){
			cin >> x >> y;
			bpGraph[x-1][y-1]=1;
			bpGraph[y-1][x-1]=1;
		}
	memset(matchR, -1, sizeof(matchR));
		int k=maxBPM();
		if(2*k==n){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		/*cout << "Maximum number of applicants that can get job is "
		  << maxBPM();*/
	}
	return 0;
}
