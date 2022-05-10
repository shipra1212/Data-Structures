//2147155 shipra jha

#include<stdio.h>
#include<conio.h>
int a,b,u,v,n,i,j,element=1;    //variable declaration
int visited[10]= {0};
int min,mincost=0,cost[10][10];
void main() 
{
	printf("\n_____________________LAB10  (Minimum Spanning Tree)_______________________");
	printf("\n___________________________________________________");
	printf("\n Enter no of nodes of MST:");                     // taking input
	scanf("%d",&n);
	printf("\n Enter the weight of adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++) {
		scanf("%d",&cost[i][j]);                               
		                                       // cost is 0 then initialize it by maximum value
		if(cost[i][j]==0)
		    cost[i][j]=999;
	}
	// to find minimum cost spanning tree
	visited[1]=1;        // visited first node
	printf("\n \n");
	while(element<n) 
	{
		  // finding minimum cost in each cycle find
		for (i=1,min=999;i<=n;i++)
		   for (j=1;j<=n;j++)
		    if(cost[i][j]<min)
		     if(visited[i]!=0) {
			min=cost[i][j];
			a=u=i;
			b=v=j;
		}
		
		 //if node is not visited
		 
		if(visited[u]==0 || visited[v]==0) {
			printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;     
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n Minimun cost=%d",mincost);
	getch();
}
