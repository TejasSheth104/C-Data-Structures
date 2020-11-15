#include<stdio.h>
#include<conio.h>
int a[5]={0,0,0,0,0},q[4],b[5],b2c[5];
	comp()
		{
			int i=4;
			do
			{
				b2c[i]=b[i];
				i--;
			}while(b[i+1]!=1);
			while(i>=0)
			{
				b2c[i]=(b[i]+1)%2;
				i--;
			}
			printf("\n\tB's complement:");
			for(i=0;i< 5;i++)
			printf("%d",b2c[i]);
			printf("\n");
			}
			nonresdiv()
			{
			shiftleft();
			if(a[0]==0)
			a_minus_b();
			else
			a_plus_b();
			q[3]=(a[0]+1)%2;
		}
	shiftleft()
		{
			int i;
			for(i=0;i< 4;i++)
			a[i]=a[i+1];
			a[4]=q[0];
			for(i=0;i< 3;i++)
			q[i]=q[i+1];
		}
		a_minus_b()
		{
			int i,carry=0,sum=0;
			for(i=4;i>=0;i--)
			{
				sum=(a[i]+b2c[i]+carry);
				a[i]=sum%2;
				carry=sum/2;
			}
		}
	a_plus_b()
		{
		int i,carry=0,sum=0;
		for(i=4;i>=0;i--)
		{
			sum=(a[i]+b[i]+carry);
			a[i]=sum%2;
			carry=sum/2;
		}
	}
void main()
	{
		int i,j,k;
		
		printf("Enter dividend in binary form\t: ");
		for(i=0;i< 4;i++)
			scanf("%d",&q[i]);
			printf("Enter divisor in binary form\t: ");
		for(i=0;i< 5;i++)
			scanf("%d",&b[i]);
			comp();
			printf("\n\t[A]\t[M]\n");
		for(i=0;i< 4;i++)
			{
			nonresdiv();
			printf("\t");
			for(j=0;j< 5;j++)
			printf("%d",a[j]);
			printf("\t");
			for(k=0;k< 4;k++)
			printf("%d",q[k]);
			printf("\n");
		}
		if(a[0]==1)
		a_plus_b();printf("\t");
		for(j=0;j< 5;j++)
			printf("%d",a[j]);
			printf("\t");
		for(k=0;k< 4;k++)
			printf("%d",q[k]);
			printf("\n");
			printf("\n\tThe Quotient Is\t: ");
		for(k=0;k< 4;k++)
			printf("%d",q[k]);
			printf("\n\tThe Remainder Is\t: ");
		for(j=0;j< 5;j++)
			printf("%d",a[j]);

	}
