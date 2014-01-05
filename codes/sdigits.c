#include<stdio.h>
long long int at[11];
long long int power[11];
int asdf[11];
long long int calc(long long int n){

	long long int sum=asdf[n%10];
	int last=n%10;
	n=n/10;
	int l;
	int i=1;
	while(n){
		l=n%10;
		sum+=l*at[i]+(l*(l-1)/2)*power[i]+l*(last+1);
		last=l*power[i]+last;
		i++;
		n=n/10;
	}
	return sum;
}
int main(){
	int i=0;
	power[0]=1;
	power[1]=10;
	for(i=2;i<=9;i++){
		power[i]=power[i-1]*10;
	}
	asdf[0]=0;
	asdf[1]=1;
	for(i=2;i<=9;i++){
		asdf[i]=i+asdf[i-1];
	}
	at[0]=1;
	at[1]=45;
	for(i=2;i<=9;i++){
		at[i]=at[i-1]*10+45*power[i-1];
	}
	while(1){
		long long int a,b;
		scanf("%lld %lld",&a,&b);
		if(a==-1 && b==-1){
			break;
		}
		if(a!=0)
			printf("%lld\n",calc(b)-calc(a-1));
		if(a==0)
			printf("%lld\n",calc(b));
	}
	return 0;
}
