#include<cstdio>
int f[524288]={0};
int pre[1000001];
int res[1000001];
struct event{
	int a,b,key,rank;
};
event e[500000];
event b[500000];
void  merge(event a[],int be,int m, int n,event b[]){
	int i=be,j=m+be,k=0;
	while(1){
		if(i==m+be || j==n+1){
			break;
		}
		if(a[i].key<=a[j].key){
			b[k]=a[i];
			k++;
			i++;

		}
		else{
			b[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<m+be){
		b[k]=a[i];
		k++;
		i++;
	}
	while(j<n+1){
		b[k]=a[j];
		k++;
		j++;
	}
	return;
}
void mergesort( event a[],int begin, int  end,event b[]){
	if(begin>=end){
		return;
	}

	int  mid=(end+1-begin)/2;
	int i,k=0;
	mergesort(a,begin,mid -1+begin,b);
	mergesort(a,mid+begin,end,b);
	merge(a,begin,mid,end,b);
	for(i=begin;i<=end;i++){
		a[i]=b[k];
		k++;
	}
	return;
}
/*void init(int n,int s,int e){
  f[n]=0;
  if(s==e){
  zero[n]=1;
  one[n]=0;
  return;
  }
  init(2*n,s,(s+e)/2);
  init(2*n+1,(s+e)/2+1,e);
  zero[n]=zero[2*n]+zero[2*n+1];
  one[n]=one[2*n]+one[2*n+1];
  return;
  }*/
void update(int n,int s,int e,int i,int j,int val){
	if(s==i && e==j){
		f[n]+=val;
		return ;
	}
	int l=(s+e)/2;
	if(j<=l)
		update(2*n,s,l,i,j,val);
	else if(i>l)
		update(2*n+1,l+1,e,i,j,val);
	else{
		update(2*n,s,l,i,l,val);
		update(2*n+1,l+1,e,l+1,j,val);

	}
	f[n]=f[2*n]+f[2*n+1];
	return ;
}
int query(int n,int s,int e,int i,int j){
	if(s==i && e==j){
		return f[n];
	}
	int l=(s+e)/2;
	int p1=0,p2=0;
	if(j<=l){
		p1=query(2*n,s,l,i,j);
	}
	else if(i>l){
		p2=query(2*n+1,l+1,e,i,j);
	}
	else{
		p1=query(2*n,s,l,i,l);
		p2=query(2*n+1,l+1,e,l+1,j);
	}
	return (p1+p2);
}
int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&e[i].a);
		e[i].b=-1;
		e[i].key=i+1;
		e[i].rank=i+1;
		pre[e[i].a]=-1;
		b[i].a=0;
		b[i].b=0;
		b[i].key=0;
		b[i].rank=0;
	}
	int j=n;
	int q;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d %d",&e[j].a,&e[j].b);
		e[j].key=e[j].b;
		e[j].rank=i+1;
		b[j].a=0;
		b[j].b=0;
		b[j].key=0;
		b[j].rank=0;
		j++;

	}

	/*for(i=0;i<n+q;i++){
	  printf("%d %d %d %d\n",e[i].a,e[i].b,e[i].key,e[i].rank);
	  }
	  printf("\n");
	 */

	mergesort(e,0,n+q-1,b);
	/*for(i=0;i<n+q;i++){
	  printf("%d %d %d %d\n",e[i].a,e[i].b,e[i].key,e[i].rank);
	  }*/

	for(i=0;i<n+q;i++){
		if(e[i].b==-1){
			if(pre[e[i].a]!=-1){
				update(1,0,n-1,pre[e[i].a]-1,pre[e[i].a]-1,-1);
			}
			update(1,0,n-1,e[i].rank-1,e[i].rank-1,1);
			pre[e[i].a]=e[i].rank;
		}
		else{
			res[e[i].rank-1]=query(1,0,n-1,e[i].a-1,e[i].b-1);
		}
	}
	for(i=0;i<q;i++){
		printf("%d\n",res[i]);
	}
	return 0;
}

