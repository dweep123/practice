#include<stdio.h>
#include<math.h>

long  long int mod;

long long unsigned int M[2][2]={{1,1},{1,0}};
void fib(long long unsigned int n){
	long long unsigned int L[2][2]={{1,1},{1,0}};
	long long unsigned int A[2][2];
	if(n>1){
		fib(n/2);
		A[0][0]=(M[0][0]*M[0][0]+M[0][1]*M[1][0])%mod;
		A[0][1]=(M[0][0]*M[0][1]+M[0][1]*M[1][1])%mod;
		A[1][0]=(M[1][0]*M[0][0]+M[1][1]*M[1][0])%mod;
		A[1][1]=(M[1][0]*M[0][1]+M[1][1]*M[1][1])%mod;
		/*A[0][0]=M[0][0]%mod*M[0][0]%mod+M[0][1]%mod*M[1][0]%mod;
		  A[0][1]=M[0][0]%mod*M[0][1]%mod+M[0][1]%mod*M[1][1]%mod;
		  A[1][0]=M[1][0]%mod*M[0][0]%mod+M[1][1]%mod*M[1][0]%mod;
		  A[1][1]=M[1][0]%mod*M[0][1]%mod+M[1][1]%mod*M[1][1]%mod;*/
		M[0][0]=A[0][0];
		M[0][1]=A[0][1];
		M[1][0]=A[1][0];
		M[1][1]=A[1][1];

		if(n%2!=0){
			A[0][0]=(M[0][0]*L[0][0]+M[0][1]*L[1][0])%mod;
			A[0][1]=(M[0][0]*L[0][1]+M[0][1]*L[1][1])%mod;
			A[1][0]=(M[1][0]*L[0][0]+M[1][1]*L[1][0])%mod;
			A[1][1]=(M[1][0]*L[0][1]+M[1][1]*L[1][1])%mod;



			/*	A[0][0]=M[0][0]%mod*L[0][0]%mod+M[0][1]%mod*L[1][0]%mod;
				A[0][1]=M[0][0]%mod*L[0][1]%mod+M[0][1]%mod*L[1][1]%mod;
				A[1][0]=M[1][0]%mod*L[0][0]%mod+M[1][1]%mod*L[1][0]%mod;
				A[1][1]=M[1][0]%mod*L[0][1]%mod+M[1][1]%mod*L[1][1]%mod;
			 */
			M[0][0]=A[0][0];
			M[0][1]=A[0][1];
			M[1][0]=A[1][0];
			M[1][1]=A[1][1];
		}
		return;
	}
	return ;
}




int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		long long unsigned int n,k;
		scanf("%llu",&n);
		mod=1000000007;
		if(n==0){
			k=0;
		}
		else{
			M[0][0]=1;
			M[0][1]=1;
			M[1][0]=1;
			M[1][1]=0;
			//	fib(2*n-1);
			fib(n+1);
			k=M[0][0]*M[0][1];
			k=k-1;
			/*k=M[0][0];
			  M[0][0]=1;
			  M[0][1]=1;
			  M[1][0]=1;
			  M[1][1]=0;
			//fib(2*n);
			fib(n+2);
			k=k*M[0][0];
			k=k-1;*/
		}

		printf("$%llu\n",k%mod);
	}
	return 0;
}



