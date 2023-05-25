#include<stdio.h>
#include<math.h>
int place(int k,int i);
void print(int n);
int board[100],count;
void nqueen(int k,int n)	//k=row
{
	for(int i=1;i<=n;i++)	//i=column
	{
		if(place(k,i))
		{
			board[k]=i;
			if(k==n)
			{
				print(n);
			}
			else
			{
				nqueen(k+1,n);
			}
		}
	}
}
int place(int k,int i)
{
	for(int j=1;j<=k-1;j++)
	{
		if(board[j]==i)
			return 0;
		else
			if(abs(board[j]-i)==abs(j-k))
				return 0;
	}
	return 1;
}
void print(int n)
{
	int i,j;
	printf("\n Solution %d: \n",++count);
	for(i=1;i<=n;i++)
	{
		printf("\t%d",i);
	}
	for(i=1;i<=n;i++)
	{
		printf("\n\n%d",i);
		for(j=1;j<=n;j++)
		{
			if(board[i]==j)
				printf("\tQ");
			else
				printf("\t-");
		}
	}
}
int main()
{
	int n,i,j;
	void nqueen(int row,int n);
	printf("\n\nEnter number of Queens: ");
	scanf("%d",&n);
	nqueen(1,n);
	return 0;
}






