//crc
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char dw[50],tw[50],q[50],g[]="10001000000100001";
int n,l,i,j,flag=0;

void xor()
{
	for(i=1;i<n;i++)
	{
		if(q[i]==g[i]) q[i]='0';
		else q[i]='1';
	}
		//q[i]=((q[i]==g[i])?'0':'1');
}
void crc()
{

	for(j=0;j<n;j++)
		q[j]=dw[j];
	do
	{
		if(q[0]=='1') xor();
		for(i=0;i<n-1;i++)
			q[i]=q[i+1];
		q[i]=dw[j++];
        printf("\nremainder is %s",q);
	}while(j<=l+n-1);//<=
	//printf("*");
}



main()
{
	printf("Enter the data");
	scanf("%s",dw);
	l=strlen(dw);
	n=strlen(g);
	printf("\nGenerator polynomial is %s",g);
	for(i=l;i<n+l-1;i++)
		dw[i]='0';
	printf("\nModified data word after appending 0 is %s",dw);
	crc();
	//printf("\nThe remainder is %s",q);
	for (i=l;i<n+l-1;i++)
		dw[i]=q[i-l];
	printf("\nThe final codeword is %s\n",dw);
	printf("Enter the transmitted word");
	scanf("%s",dw);
	crc();
	printf("\n%s",q);
	for(i=0;i<n-1;i++)//<n-1
		if(q[i]!='0') flag=1;
	if(flag) printf("\nError in transmissiom");
	else printf("\nNo error in transmission");

}
