#include<stdio.h>
int main(){

	int n,i,j=0,k,a[100],b[100],count=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<n;i++){
		if(a[i]==1)
		{
			b[j]=a[i];
			for(k=i+1;k<n&&a[k]==1&&count<5;k++){
				j++;
				b[j]=a[k];
				count++;
			if(count==5){
				j++;
				b[j]=0;
				}
			i=k;
			}
		}
		
		else{
		b[j]=a[i];
		}
		i++;
		j++;
		}
		
		for(i=0;i<=j;i++){
		printf("%d",b[i]);
		}
		}
