#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char res[100];
void sender()
{
	int n,i,len;
	char frm[100],l[100];
	printf("Enter the number of frames\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the frame %d\n",i+1);	
		scanf("%s",frm);
		len=strlen(frm);
		sprintf(l,"%d",len);
		strcat(l,frm);
		strcat(res,l);
	}
	printf("The final message is %s\n",res);
}
void reciever()
{
	int len,i,j;
	printf("Received frame \n");
	for(i=0;i<strlen(res);i++)
	{
		len=res[i]-'0';
		for(j=i+1;j<=(i+len);j++)
			printf("%c",res[j]);
		i=i+len;
		printf("\n");
	}
}
void main()
{
	sender();
	reciever();
	
}

