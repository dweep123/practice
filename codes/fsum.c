#include<stdio.h>
#include<math.h>

long  long int mod;

long long  int M[2][2]={{1,1},{1,0}};
void fib(int n){
	long long int L[2][2]={{1,1},{1,0}};
		long long int A[2][2];
			if(n>1){
					fib(n/2);
							A[0][0]=(M[0][0]*M[0][0]+M[0][1]*M[1][0])%mod;
									A[0][1]=(M[0][0]*M[0][1]+M[0][1]*M[1][1])%mod;
											A[1][0]=(M[1][0]*M[0][0]+M[1][1]*M[1][0])%mod;
													A[1][1]=(M[1][0]*M[0][1]+M[1][1]*M[1][1])%mod;
															M[0][0]=A[0][0];
																	M[0][1]=A[0][1];
																			M[1][0]=A[1][0];
																					M[1][1]=A[1][1];

																							if(n%2!=0){
																										A[0][0]=(M[0][0]*L[0][0]+M[0][1]*L[1][0])%mod;
																													A[0][1]=(M[0][0]*L[0][1]+M[0][1]*L[1][1])%mod;
																																A[1][0]=(M[1][0]*L[0][0]+M[1][1]*L[1][0])%mod;
																																			A[1][1]=(M[1][0]*L[0][1]+M[1][1]*L[1][1])%mod;



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
																																																						long int tc;
																																																							scanf("%ld",&tc);
																																																								while(tc--){
																																																										int n;
																																																												int m;
																																																														long long int k;
																																																																scanf("%d %d",&n,&m);
																																																																		mod=1000000007;
																																																																				if(n==0 || n==1) {
																																																																							M[0][0]=1;
																																																																										M[0][1]=1;
																																																																													M[1][0]=1;
																																																																																M[1][1]=0;
																																																																																			fib(m+1);
																																																																																						k=(M[0][0]-1)%mod;
																																																																																								}
																																																																																										else{
																																																																																													M[0][0]=1;
																																																																																																M[0][1]=1;
																																																																																																			M[1][0]=1;
																																																																																																						M[1][1]=0;
																																																																																																									fib(m+1);
																																																																																																												k=M[0][0]-1;
																																																																																																															M[0][0]=1;
																																																																																																																		M[0][1]=1;
																																																																																																																					M[1][0]=1;
																																																																																																																								M[1][1]=0;
																																																																																																																											fib(n);
																																																																																																																														k=(k-(M[0][0]-1))%mod;
																																																																																																																																}
																																																																																																																																		if(k < 0){
																																																																																																																																					k=k+mod;
																																																																																																																																							}
																																																																																																																																									printf("%lld\n",k);
																																																																																																																																										}
																																																																																																																																											return 0;
																																																																																																																																											}

