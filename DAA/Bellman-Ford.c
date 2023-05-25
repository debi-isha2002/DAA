#include<stdio.h>
#define inf 999
struct node{
    int u;
    int v;
    int cost;
};
struct node gr[10];
int graph[10][10],n,m;
int bellmanford()
{
    int pred[10],wt[10],i,j,k;
    for(i=0;i<n;i++)
    {
        wt[i]=inf;
        pred[i]=0;
    }
    wt[0]=0;
    for(j=0;j<n-1;j++)
    {
        for(i=0;i<m;i++)
        {
            if(wt[gr[i].u]+gr[i].cost<wt[gr[i].v])
            {
              wt[gr[i].v]=wt[gr[i].u]+gr[i].cost;
              pred[gr[i].v]=gr[i].u;  
            }
        }
    }
    for(i=0;i<m;i++)
        {
            if(wt[gr[i].u]+gr[i].cost<wt[gr[i].v])
            {
             return 0;
            }
        }
        printf("\nthe shortst path is:"); 
    for(i=0;i<n;i++)
    {
        printf("\n%c-----%d",i+65,wt[i]);
    }
}
int main()
{
   int i,j;
    FILE *fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL)
    {
        printf("\nerror to open the file\n");
    }
    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
    printf("the graph is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
    }
     m=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(graph[i][j]!=0)
            {
                gr[m].u=i;
                gr[m].v=j;
                gr[m].cost=graph[i][j];
                m++;
            }
        }
    }
    bellmanford();
    return 0;
}
