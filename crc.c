#include<stdio.h>
#include<string.h>
#define N strlen(gen_pol)
char data[20];
char check_value[20];
char gen_pol[20];
int data_len,i,j;

void XOR()
{
    for(j=0;j<N;j++)
    check_value[j]=((check_value[j]==gen_pol[j])?'0':'1'); 
}

void crc()
{
    for(i=0;i<N;i++)
    check_value[i]=data[i];
    
    do{
        if(check_value[0]=='1')
        XOR();
        for(j=0;j<N-1;j++)
        check_value[j]=check_value[j+1];
        check_value[j]=data[i++];
    }while(i<=data_len+N-1);
}
void receiver(){
    printf("enter the receiver data: %s\n",data);
    crc();
    for(i=0;i<N-1&&check_value[i]!='1';i++);
    if(i<N-1)
        printf("error detected:");
    else
        printf("no error detected");
}

void main()
{
    printf("enter the data to be transmitted:");
    scanf("%s",data);
    
    printf("enter genrator polynomial:");
    scanf("%s",gen_pol);
    
    data_len=strlen(data);
    for(i=data_len;i<data_len+N-1;i++)
    data[i]='0';
    
    printf("After padding: %s\n",data);
    crc();
    
    printf("CRC is %s",check_value);
    for(i=data_len;i<data_len+N-1;i++)
    data[i]=check_value[i-data_len];
    printf("final data sent: %s\n",data);
    receiver();
}

