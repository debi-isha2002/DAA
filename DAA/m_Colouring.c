#include<stdio.h>
#define max 10
int graph[max][max],x[max];
int n,m,false=0,count=0;
void next_value(int k)
{
	int j;
	do{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		for(j=1;j<=k-1;j++)
		{
			if(graph[k][j]==1 && x[j]==x[k])
				break;
		}
		if(j==k)
			return;
	}while(!false);
}
void m_colouring(int k)
{
	int i;
	do{
		next_value(k);
		if(x[k]==0)
			return;
		if(k==n)
		{
			count++;
			printf("\n Solution No. : %d: \n",count);
			for(i=1;i<=n;i++)
			{ 
				printf("%d \t",x[i]);
			}
			printf("\n");
		}
		else
		{
			m_colouring(k+1);
		}
	}while(!false);
}
int main()
{
	int i,j,k=1;
	FILE *fp;
	printf("m-Colouring Problem:\n");
	printf("\n Enter number of Colours: ");
	scanf("%d",&m);
	fp=fopen("m_colouring.txt","r");
	if(fp==NULL)
	{
		printf("Error to open the file\n\n");
			return;
	}
	fscanf(fp,"%d",&n);
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	printf("\nThe graph in matrix form:\n\t");
	for(i=1;i<=n;i++)
	{
		printf("%c\t",i+64);
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("%c\t",i+64);
		for(j=1;j<=n;j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	printf("\nSolution: \n");
	m_colouring(k);
	if(count==0)
		printf("Doesn't exist");
	fclose(fp);
	return 0;
}









