#include<stdio.h>
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		int a[n],c[n];
		int i;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++){
			scanf("%d",&c[i]);
		}

		int min;
		int temp;
		int j;
		for(i=0;i<n;i++){
			min=i;
			for(j=i+1;j<n;j++){
				if(a[j] < a[min]){
					min=j;
				}
				else if(a[j]==a[min]){
					if(c[j] <= c[min]){
						min=j;
					}
				}
			}
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
			temp=c[i];
			c[i]=c[min];
			c[min]=temp;
		}


		int len[n];
		len[0]=1;
		int max=1;
		int y;
		for(i=1;i<n;i++){
			len[i]=1;
			for(j=0;j<i;j++){
				if(c[j] <= c[i]){
					if(len[j]+1 >= len[i]){
						len[i]=len[j]+1;
					}
				}
			}
			if(len[i]> max){
				max=len[i];
			}
		}
		printf("%d\n",max);


		/*for(i=0;i<n;i++){
		  printf("%d ",a[i]);
		  }
		  printf("\n");
		  for(i=0;i<n;i++){
		  printf("%d ",c[i]);
		  }
		  printf("\n");*/
		/*int aux[n];
		  aux[0]=c[0];
		  int len=1;
		  for(i=1;i<n;i++){
		  if(c[i] < aux[0]){
		  aux[0]=c[i];
		  }
		  else if(c[i] >= aux[len-1]){
		  aux[len++]=c[i];
		  }
		  else{
		  aux[bsearch(0,len-1,aux,c[i])]=c[i];
		  }
		  }
		  printf("%d\n",len);*/
	}
	return 0;
}

