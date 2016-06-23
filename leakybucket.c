#include<stdio.h>
#include<stdlib.h>

main()
{
    int size,outrate,ch,data[10],i,t,ts;
    int bucketfilled=0;
    printf("Enter the size of bucket");
    scanf("%d",&size);
    printf("Enter the output rate");
    scanf("%d",&outrate);
    printf("Enter the no of timestamps");
    scanf("%d",&ts);
    printf("Enter the data flow at each second");
    for (i=0;i<ts;i++)
    {
        printf("second %d",i+1);
        scanf("%d",&data[i]);
    }
    printf("time\tinput\tout flow\tdata in bucket\n");
    t=0;

    while(1)
    {
        if(t<ts)
        bucketfilled+=data[t];
        if(bucketfilled>outrate)
         {
            bucketfilled-=outrate;
            if(t>ts)
            printf("%d\t0\t%d\t%d\n",t,outrate,bucketfilled);
            else
            printf("%d\t%d\t%d\t%d\n",t,data[t],outrate,bucketfilled);
         }
         else if(bucketfilled>0)
         {

            printf("%d\t%d\t%d\t0\n",t,data[t],bucketfilled);

            bucketfilled=0;
         }
         else
                printf("\nThe bucket is empty\n");
         t++;
         if(t>ts && bucketfilled==0)
            exit(0);
    }
 }




