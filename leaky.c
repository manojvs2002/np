#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int i,packets[5],content =0,newcontent,time,clck,bucketsize,outputrate;
    for(i=0;i<5;i++)
    {
        packets[i]=rand()%10;
        if(packets[i]==0) --i;
    }
    printf("Enter the ouput rate of the bucket\n");
    scanf("%d",&outputrate);
    printf("enter the bucket size");
    scanf("%d",&bucketsize);
    for ( i = 0; i <5; i++)
    {
        if((packets[i]+content)>bucketsize)
        {
            if(packets[i]>bucketsize)
            {
                printf("Incoming packet size is greater than bucket size");
            }
            else{
                printf("buckets size exceeded");
            }
        }
        else
        {
            newcontent = packets[i];
            content=content+newcontent;
            printf("Incoming packet is %d",newcontent);
            printf("transmission left is %d",content);
            time = rand()%10;
            printf("Next packet will come at %d",time);
            for(clck =0;clck<time && content>0;++clck)
            {
                printf("The time left is %d",(time-clck));
                sleep(1);
                if (content)
                {
                    printf("Transmitted\n");
                    if(content<outputrate)
                    {
                        content=0;
                    }
                    else
                    {
                        content = content-outputrate;
                        printf("the bytes remaining is %d",content);
                    }
                }
                else
                {
                    printf("No content to transmit\n");
                }
                
            }
        }
    }    

}
